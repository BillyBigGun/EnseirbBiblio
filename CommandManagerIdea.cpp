class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class AddCommand : public Command {
public:
    AddCommand(Library& library) : library_(library) {}

    void execute() override {
        library_.addMedia();
    }

private:
    Library& library_;
};

class RemoveCommand : public Command {
public:
    RemoveCommand(Library& library) : library_(library) {}

    void execute() override {
        library_.removeMedia();
    }

private:
    Library& library_;
};



class CommandFactory {
public:
    CommandFactory(Library& library) : library_(library) {
        commands["ADD"] = [&]() { return std::make_unique<AddCommand>(library_); };
        commands["REMOVE"] = [&]() { return std::make_unique<RemoveCommand>(library_); };
    }

    void executeCommand(const std::string& command) {
        auto it = commands.find(command);
        if (it == commands.end()) {
            throw std::invalid_argument("Invalid command: " + command);
        }
        it->second()->execute();
    }

private:
    std::map<std::string, std::function<std::unique_ptr<Command>()>> commands;
    Library& library_;
};