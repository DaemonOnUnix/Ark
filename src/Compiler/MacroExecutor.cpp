#include <Ark/Compiler/MacroProcessor.hpp>
#include <Ark/Compiler/MacroExecutor.hpp>

namespace Ark::internal
{
    MacroExecutor::MacroExecutor(MacroProcessor* macroprocessor, unsigned int debug) : m_macroprocessor(macroprocessor), m_debug(debug)
    {
    }

    Node* MacroExecutor::find_nearest_macro(const std::string& name)
    {
        return m_macroprocessor->find_nearest_macro(name);
    }

    void MacroExecutor::registerMacro(Node& node)
    {
        m_macroprocessor->registerMacro(node);
    }

    bool MacroExecutor::isTruthy(const Node& node)
    {
        return m_macroprocessor->isTruthy(node);
    }

    Node MacroExecutor::evaluate(Node& node, bool is_not_body)
    {
        return m_macroprocessor->evaluate(node, is_not_body);
    }
    void MacroExecutor::unify(const std::unordered_map<std::string, Node>& map, Node& target, Node* parent)
    {
        m_macroprocessor->unify(map, target, parent);
    }
    void MacroExecutor::throwMacroProcessingError(const std::string& message, const Node& node)
    {
        m_macroprocessor->throwMacroProcessingError(message, node);
    }
    void MacroExecutor::execute_proxy(Node& node)
    {
        m_macroprocessor->execute(node);
    }
}