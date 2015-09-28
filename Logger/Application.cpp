#include "Application.h"

#include "logging/ConsoleLogger.h"
#include "logging/LogManager.h"
#include "logging/LogLevel.h"

#include <QObject>
#include <QString>

using namespace logger;
using namespace logger::logging;
using namespace std;

Application::Application()
    :QObject(){
    // Logging
    this->setupLogging();

    m_logger->log("Settings loaded", LogLevel::INFO);
    m_logger->log("debunked", LogLevel::DEBUG);

}

Application::~Application() {
}

std::shared_ptr<logging::ConsoleLogger>
Application::consoleLogger() const {
    return m_consoleLogger;
}

std::shared_ptr<logging::LogManager>
Application::logManager() const {
    return m_logManager;
}

void
Application::setupLogging() {
    m_logManager = shared_ptr<LogManager>(new LogManager(this));
    // TODO put the default log levels in an enum
    m_logger = m_logManager->logger("Application");

    m_consoleLogger = std::shared_ptr<logging::ConsoleLogger>(new logging::ConsoleLogger(this));
    m_consoleLogger->connect(m_logger);

    // print an initial message to show it works
    m_logger->log("Logging initialized", LogLevel::DEBUG);
}
