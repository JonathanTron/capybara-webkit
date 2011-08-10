#include "Reset.h"
#include "WebPage.h"
#include "NetworkAccessManager.h"
#include <QNetworkReply>

Reset::Reset(WebPage *page, QObject *parent) : Command(page, parent) {
}

void Reset::start(QStringList &arguments) {
  Q_UNUSED(arguments);

  page()->triggerAction(QWebPage::Stop);
  page()->currentFrame()->setHtml("<html><body></body></html>");
  page()->networkAccessManager()->setCookieJar(new QNetworkCookieJar());
  page()->setNetworkAccessManager(new NetworkAccessManager());
  connect(page()->networkAccessManager(), SIGNAL(finished(QNetworkReply*)), page(), SLOT(requestFinished(QNetworkReply*)));
  page()->setUserAgent(NULL);
  page()->resetResponses();
  emit finished(new Response(true));
}

