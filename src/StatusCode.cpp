#include "StatusCode.h"
#include "WebPage.h"

StatusCode::StatusCode(WebPage *page, QObject *parent) : Command(page, parent) {
}

void StatusCode::start(QStringList &arguments) {
  Q_UNUSED(arguments);
  QString response;
  response.setNum(page()->statusCode());
  emit finished(true, response);
}

