#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <mutex>
class Server 
{
public:
    Server(
        const std::string& address, 
        int port,
        int weight = 1
    );
    // Get server address
    std::string getAddress() const;
    // Get server port
    int getPort() const;
    // Get server weight
    int getWeight() const;
    // Get current connection count
    int getConnectionCount() const;
    // Increment connection count
    void incrementConnections();
    // Decrement connection count
    void decrementConnections();
    // Check if server is healthy
    bool isHealthy() const;
    // Set server health status
    void setHealth(bool healthy);
    // Perform health check
    bool checkHealth();

private:
    std::string address_;
    int port_;
    int weight_;
    int connections_;
    bool healthy_;
    mutable std::mutex mutex_;
};
#endif // SERVER_H