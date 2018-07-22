
// Generated from /Users/thosakwe/Source/Compilers/manda/src/manda_text/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace manda_text {


class  MandaParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    WS = 21, DOC_COMMENT = 22, SINGLE_LINE_COMMENT = 23, SINGLE_QUOTED_STRING = 24, 
    DECIMAL = 25, BINARY = 26, HEX = 27, OCTAL = 28, ID = 29
  };

  enum {
    RuleProgram = 0, RuleComment = 1, RuleDirective = 2, RuleStatement = 3, 
    RuleVariableModifier = 4, RuleType = 5, RuleStructTypeField = 6, RuleTypeAnnotation = 7, 
    RuleTypeParameter = 8, RuleTypeParameterList = 9, RuleTypeArgumentList = 10, 
    RuleArgumentList = 11, RuleNamedArgument = 12, RuleExpression = 13, 
    RuleLiteral = 14, RuleString = 15
  };

  MandaParser(antlr4::TokenStream *input);
  ~MandaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class CommentContext;
  class DirectiveContext;
  class StatementContext;
  class VariableModifierContext;
  class TypeContext;
  class StructTypeFieldContext;
  class TypeAnnotationContext;
  class TypeParameterContext;
  class TypeParameterListContext;
  class TypeArgumentListContext;
  class ArgumentListContext;
  class NamedArgumentContext;
  class ExpressionContext;
  class LiteralContext;
  class StringContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DirectiveContext *> directive();
    DirectiveContext* directive(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CommentContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CommentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DocCommentContext : public CommentContext {
  public:
    DocCommentContext(CommentContext *ctx);

    antlr4::tree::TerminalNode *DOC_COMMENT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SingleLineCommentContext : public CommentContext {
  public:
    SingleLineCommentContext(CommentContext *ctx);

    antlr4::tree::TerminalNode *SINGLE_LINE_COMMENT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CommentContext* comment();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DirectiveContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DirectiveContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ImportDirectiveContext : public DirectiveContext {
  public:
    ImportDirectiveContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WithDirectiveContext : public DirectiveContext {
  public:
    WithDirectiveContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypedefDirectiveContext : public DirectiveContext {
  public:
    TypedefDirectiveContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DirectiveContext* directive();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpressionStatementContext : public StatementContext {
  public:
    ExpressionStatementContext(StatementContext *ctx);

    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStatementContext : public StatementContext {
  public:
    ReturnStatementContext(StatementContext *ctx);

    ExpressionContext *expression();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableDeclarationStatementContext : public StatementContext {
  public:
    VariableDeclarationStatementContext(StatementContext *ctx);

    VariableModifierContext *variableModifier();
    antlr4::tree::TerminalNode *ID();
    ExpressionContext *expression();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    TypeAnnotationContext *typeAnnotation();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  VariableModifierContext : public antlr4::ParserRuleContext {
  public:
    VariableModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariableModifierContext() : antlr4::ParserRuleContext() { }
    void copyFrom(VariableModifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarModifierContext : public VariableModifierContext {
  public:
    VarModifierContext(VariableModifierContext *ctx);

    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LetModifierContext : public VariableModifierContext {
  public:
    LetModifierContext(VariableModifierContext *ctx);

    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VariableModifierContext* variableModifier();

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

    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructTypeContext : public TypeContext {
  public:
    StructTypeContext(TypeContext *ctx);

    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    std::vector<StructTypeFieldContext *> structTypeField();
    StructTypeFieldContext* structTypeField(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedTypeContext : public TypeContext {
  public:
    ParenthesizedTypeContext(TypeContext *ctx);

    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierTypeContext : public TypeContext {
  public:
    IdentifierTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    TypeParameterListContext *typeParameterList();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  StructTypeFieldContext : public antlr4::ParserRuleContext {
  public:
    StructTypeFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructTypeFieldContext* structTypeField();

  class  TypeAnnotationContext : public antlr4::ParserRuleContext {
  public:
    TypeAnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAnnotationContext* typeAnnotation();

  class  TypeParameterContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeParameterContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TypeParameterContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdentifierTypeParameterContext : public TypeParameterContext {
  public:
    IdentifierTypeParameterContext(TypeParameterContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExtendsTypeParameterContext : public TypeParameterContext {
  public:
    ExtendsTypeParameterContext(TypeParameterContext *ctx);

    antlr4::tree::TerminalNode *ID();
    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeParameterContext* typeParameter();

  class  TypeParameterListContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeParameterContext *> typeParameter();
    TypeParameterContext* typeParameter(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParameterListContext* typeParameterList();

  class  TypeArgumentListContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentListContext* typeArgumentList();

  class  ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArgumentListContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ArgumentListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MixedParameterListContext : public ArgumentListContext {
  public:
    MixedParameterListContext(ArgumentListContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<NamedArgumentContext *> namedArgument();
    NamedArgumentContext* namedArgument(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NamedParameterListContext : public ArgumentListContext {
  public:
    NamedParameterListContext(ArgumentListContext *ctx);

    std::vector<NamedArgumentContext *> namedArgument();
    NamedArgumentContext* namedArgument(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositionalParameterListContext : public ArgumentListContext {
  public:
    PositionalParameterListContext(ArgumentListContext *ctx);

    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgumentListContext* argumentList();

  class  NamedArgumentContext : public antlr4::ParserRuleContext {
  public:
    NamedArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExpressionContext *expression();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedArgumentContext* namedArgument();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MemberExpressionContext : public ExpressionContext {
  public:
    MemberExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralExpressionContext : public ExpressionContext {
  public:
    LiteralExpressionContext(ExpressionContext *ctx);

    LiteralContext *literal();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExpressionContext : public ExpressionContext {
  public:
    IdExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExpressionContext : public ExpressionContext {
  public:
    CallExpressionContext(ExpressionContext *ctx);

    MandaParser::ExpressionContext *target = nullptr;
    ArgumentListContext *argumentList();
    ExpressionContext *expression();
    TypeArgumentListContext *typeArgumentList();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsExpressionContext : public ExpressionContext {
  public:
    AsExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    TypeContext *type();
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryLiteralContext : public LiteralContext {
  public:
    BinaryLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *BINARY();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLiteralContext : public LiteralContext {
  public:
    StringLiteralContext(LiteralContext *ctx);

    StringContext *string();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OctalLiteralContext : public LiteralContext {
  public:
    OctalLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *OCTAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecimalLiteralContext : public LiteralContext {
  public:
    DecimalLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *DECIMAL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  HexLiteralContext : public LiteralContext {
  public:
    HexLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *HEX();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext* literal();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SINGLE_QUOTED_STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

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

}  // namespace manda_text
