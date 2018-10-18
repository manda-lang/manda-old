
// Generated from /Users/thosakwe/Source/Compilers/manda/compiler/src/parser/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace parser {


class  MandaParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, Whitespace = 30, FloatLiteral = 31, 
    HexLiteral = 32, IntegerLiteral = 33, Identifier = 34
  };

  enum {
    RuleCompilationUnit = 0, RuleDirective = 1, RuleImportDirective = 2, 
    RuleTypeAliasDecl = 3, RuleFuncDecl = 4, RuleFunctionBody = 5, RuleParameterList = 6, 
    RuleParameter = 7, RuleBlock = 8, RuleType = 9, RuleStructTypeMember = 10, 
    RuleStmt = 11, RuleVarDecl = 12, RuleExpr = 13
  };

  MandaParser(antlr4::TokenStream *input);
  ~MandaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompilationUnitContext;
  class DirectiveContext;
  class ImportDirectiveContext;
  class TypeAliasDeclContext;
  class FuncDeclContext;
  class FunctionBodyContext;
  class ParameterListContext;
  class ParameterContext;
  class BlockContext;
  class TypeContext;
  class StructTypeMemberContext;
  class StmtContext;
  class VarDeclContext;
  class ExprContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DirectiveContext *> directive();
    DirectiveContext* directive(size_t i);
    std::vector<TypeAliasDeclContext *> typeAliasDecl();
    TypeAliasDeclContext* typeAliasDecl(size_t i);
    std::vector<FuncDeclContext *> funcDecl();
    FuncDeclContext* funcDecl(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImportDirectiveContext *importDirective();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectiveContext* directive();

  class  ImportDirectiveContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *symbol = nullptr;;
    ImportDirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportDirectiveContext* importDirective();

  class  TypeAliasDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *alias = nullptr;;
    TypeAliasDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAliasDeclContext* typeAliasDecl();

  class  FuncDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;;
    MandaParser::TypeContext *returnType = nullptr;;
    FuncDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterListContext *parameterList();
    FunctionBodyContext *functionBody();
    antlr4::tree::TerminalNode *Identifier();
    TypeContext *type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDeclContext* funcDecl();

  class  FunctionBodyContext : public antlr4::ParserRuleContext {
  public:
    FunctionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionBodyContext* functionBody();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *propertyKeyword = nullptr;;
    antlr4::Token *name = nullptr;;
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BlockContext() : antlr4::ParserRuleContext() { }
    void copyFrom(BlockContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EmptyBlockContext : public BlockContext {
  public:
    EmptyBlockContext(BlockContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CurlyBlockContext : public BlockContext {
  public:
    CurlyBlockContext(BlockContext *ctx);

    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrowBlockContext : public BlockContext {
  public:
    ArrowBlockContext(BlockContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BlockContext* block();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnionTypeContext : public TypeContext {
  public:
    UnionTypeContext(TypeContext *ctx);

    MandaParser::TypeContext *left = nullptr;
    MandaParser::TypeContext *right = nullptr;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructTypeContext : public TypeContext {
  public:
    StructTypeContext(TypeContext *ctx);

    std::vector<StructTypeMemberContext *> structTypeMember();
    StructTypeMemberContext* structTypeMember(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenTypeContext : public TypeContext {
  public:
    ParenTypeContext(TypeContext *ctx);

    TypeContext *type();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdTypeContext : public TypeContext {
  public:
    IdTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  StructTypeMemberContext : public antlr4::ParserRuleContext {
  public:
    StructTypeMemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StructTypeMemberContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StructTypeMemberContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StructTypeConstructorContext : public StructTypeMemberContext {
  public:
    StructTypeConstructorContext(StructTypeMemberContext *ctx);

    antlr4::Token *name = nullptr;
    ParameterListContext *parameterList();
    FunctionBodyContext *functionBody();
    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructTypeGetterContext : public StructTypeMemberContext {
  public:
    StructTypeGetterContext(StructTypeMemberContext *ctx);

    antlr4::Token *name = nullptr;
    TypeContext *type();
    FunctionBodyContext *functionBody();
    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructTypeSetterContext : public StructTypeMemberContext {
  public:
    StructTypeSetterContext(StructTypeMemberContext *ctx);

    antlr4::Token *name = nullptr;
    TypeContext *type();
    FunctionBodyContext *functionBody();
    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructTypeFieldContext : public StructTypeMemberContext {
  public:
    StructTypeFieldContext(StructTypeMemberContext *ctx);

    antlr4::Token *name = nullptr;
    TypeContext *type();
    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StructTypeMemberContext* structTypeMember();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprStmtContext : public StmtContext {
  public:
    ExprStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDeclStmtContext : public StmtContext {
  public:
    VarDeclStmtContext(StmtContext *ctx);

    std::vector<VarDeclContext *> varDecl();
    VarDeclContext* varDecl(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TryStmtContext : public StmtContext {
  public:
    TryStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IntegerExprContext : public ExprContext {
  public:
    IntegerExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *IntegerLiteral();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatExprContext : public ExprContext {
  public:
    FloatExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *FloatLiteral();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueExprContext : public ExprContext {
  public:
    TrueExprContext(ExprContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierExprContext : public ExprContext {
  public:
    IdentifierExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  HexExprContext : public ExprContext {
  public:
    HexExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *HexLiteral();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddOrSubExprContext : public ExprContext {
  public:
    AddOrSubExprContext(ExprContext *ctx);

    MandaParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MandaParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public ExprContext {
  public:
    ParenExprContext(ExprContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivOrModExprContext : public ExprContext {
  public:
    MulDivOrModExprContext(ExprContext *ctx);

    MandaParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MandaParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseExprContext : public ExprContext {
  public:
    FalseExprContext(ExprContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolAndOrExprContext : public ExprContext {
  public:
    BoolAndOrExprContext(ExprContext *ctx);

    MandaParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    MandaParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser
