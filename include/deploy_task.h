#ifndef DEPLOY_TASK_HEAD
#define DEPLOY_TASK_HEAD
#include <string>
namespace deploy
{
    class deploy_task
    {
    public:
        void callback(std::string name);

        void start(std::string name);

        void stop();

        void set_name(std::string name);

        std::string get_name();

    private:
        std::string name;
    }; // end class deploy_task
} // end namespace deploy

#endif