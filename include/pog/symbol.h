#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <pog/precedence.h>

namespace pog {

enum class SymbolKind
{
	//Start,
	End,
	Nonterminal,
	Terminal
};

template <typename ValueT>
class Symbol
{
public:
	Symbol(std::uint32_t index, SymbolKind kind, const std::string& name) : _index(index), _kind(kind), _name(name) {}

	std::uint32_t get_index() const { return _index; }
	const Precedence& get_precedence() const { return _precedence.value(); }

	void set_kind(SymbolKind kind) { _kind = kind; }
	void set_precedence(std::uint32_t level, Associativity assoc) { _precedence = Precedence{level, assoc}; }

	bool has_precedence() const { return static_cast<bool>(_precedence); }
	bool is_end() const { return _kind == SymbolKind::End; }
	bool is_nonterminal() const { return _kind == SymbolKind::Nonterminal; }
	bool is_terminal() const { return _kind == SymbolKind::Terminal; }

	const std::string& get_name() const { return _name; }

private:
	std::uint32_t _index;
	SymbolKind _kind;
	std::string _name;
	std::optional<Precedence> _precedence;
};

} // namespace pog
