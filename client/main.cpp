#include <SFML/Network.hpp>

int main(int argc, char const *argv[])
{
    auto addresses = sf::Dns::resolve("127.0.0.1");
    if(!addresses || addresses->empty())
    {
        // TODO: выбросить исключение
    }

    return 0;
}
