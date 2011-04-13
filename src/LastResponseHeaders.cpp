#include "LastResponseHeaders.h"
#include "WebPage.h"
#include <iostream>

LastResponseHeaders::LastResponseHeaders(WebPage *page, QObject *parent) : Command(page, parent) {
}

void LastResponseHeaders::start(QStringList &arguments) {
  Q_UNUSED(arguments);

  QString json;
  QTextStream jsonStream(&json);
  jsonStream << "[";

  QList< QList<QNetworkReply::RawHeaderPair> > responses = page()->responses();
  QListIterator< QList<QNetworkReply::RawHeaderPair> > responsesIterator(responses);
  while ( responsesIterator.hasNext() ) {
    QList<QNetworkReply::RawHeaderPair> headers = responsesIterator.next();
    QListIterator<QNetworkReply::RawHeaderPair> headersIterator(headers);
    jsonStream << "{";
    while ( headersIterator.hasNext() ) {
      QNetworkReply::RawHeaderPair pair = headersIterator.next();
      jsonStream << 
        "\"" << pair.first.data() << "\":\"" << pair.second.data() << "\"";
      if ( headersIterator.hasNext() )
        jsonStream << ",";
    }
    jsonStream << "}";
    if (responsesIterator.hasNext())
      jsonStream << ",";
  }
  jsonStream << "]";

  emit finished(true, json);
}