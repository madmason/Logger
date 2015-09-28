#ifndef APPLICATION_H
#define APPLICATION_H

#include "logging/ConsoleLogger.h"
#include "logging/LogManager.h"

#include <QSettings>

#include <memory>

namespace logger {

class Application
    :public QObject{
    Q_OBJECT
private:
    std::shared_ptr<logging::LogManager> m_logManager;
    std::shared_ptr<logging::ConsoleLogger> m_consoleLogger;

    void defaultSetting(QString name, QVariant defaultValue);
    void checkSettings();
    void setupLogging();

    /**
     * @brief m_logger the logger used by everything related to the application itself.
     */
    std::shared_ptr<logging::Logger> m_logger;

public:

    explicit Application();
    virtual ~Application();


    std::shared_ptr<logging::ConsoleLogger> consoleLogger() const;
    std::shared_ptr<logging::LogManager> logManager() const;

    static Application* instance();
/*signals:

    // --- forwarded signals ---
    // ApplicationContext -> Quantor
    void signal_quantorTriggered(Document* document, QStringList targetFunctions);

    // Quantor -> ApplicationContext -> MainWindow
    void signal_quantorSolutionAvailable(QString, const QMap<QString, bool>*);

public slots:
    void slot_resetSettings();*/

};

} // namespace q2d

#endif // APPLICATION_H
