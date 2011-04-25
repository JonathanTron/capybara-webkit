#include <QtWebKit>

class QNetworkReply;

class WebPage : public QWebPage {
  Q_OBJECT

  public:
    WebPage(QObject *parent = 0);
    QVariant invokeCapybaraFunction(const char *name, QStringList &arguments);
    QVariant invokeCapybaraFunction(QString &name, QStringList &arguments);
    QString failureString();
    bool render(const QString &fileName);
    void resetResponses();
    QList< QList<QNetworkReply::RawHeaderPair> > responses();

  public slots:
    bool shouldInterruptJavaScript();
    void injectJavascriptHelpers();
    void loadStarted();
    void loadFinished(bool);
    bool isLoading() const;
    void frameCreated(QWebFrame *);
    void requestFinished(QNetworkReply*);
    int statusCode();

  protected:
    virtual void javaScriptConsoleMessage(const QString &message, int lineNumber, const QString &sourceID);
    virtual void javaScriptAlert(QWebFrame *frame, const QString &message);
    virtual bool javaScriptConfirm(QWebFrame *frame, const QString &message);
    virtual bool javaScriptPrompt(QWebFrame *frame, const QString &message, const QString &defaultValue, QString *result);

  private:
    QString m_capybaraJavascript;
    bool m_loading;
    QList< QList<QNetworkReply::RawHeaderPair> > m_responses_headers;
    int m_status_code;
};

