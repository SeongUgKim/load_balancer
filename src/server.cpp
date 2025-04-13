#include "server.h"

Server::Server(const std::string& address, int port, int weight)
    : address_(address), port_(port), weight_(weight), connections_(0), healthy_(true)
{
}

std::string Server::getAddress() const
{
    return address_;
}

int Server::getPort() const
{
    return port_;
}

int Server::getWeight() const
{
    return weight_;
}

int Server::getConnectionCount() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return connections_;
}

void Server::incrementConnections()
{
    std::lock_guard<std::mutex> lock(mutex_);
    connections_++;
}

void Server::decrementConnections()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (connections_ > 0)
    {
        connections_--;
    }
}

bool Server::isHealthy() const
{
    return healthy_;
}

void Server::setHealth(bool healthy)
{
    healthy_ = healthy;
}

bool Server::checkHealth()
{
    return isHealthy();
}
