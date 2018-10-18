
// Generated from /Users/thosakwe/Source/Compilers/manda/compiler/src/parser/Manda.g4 by ANTLR 4.7


#include "MandaVisitor.h"

#include "MandaParser.h"


using namespace antlrcpp;
using namespace parser;
using namespace antlr4;

MandaParser::MandaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MandaParser::~MandaParser() {
  delete _interpreter;
}

std::string MandaParser::getGrammarFileName() const {
  return "Manda.g4";
}

const std::vector<std::string>& MandaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MandaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

MandaParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MandaParser::DirectiveContext *> MandaParser::CompilationUnitContext::directive() {
  return getRuleContexts<MandaParser::DirectiveContext>();
}

MandaParser::DirectiveContext* MandaParser::CompilationUnitContext::directive(size_t i) {
  return getRuleContext<MandaParser::DirectiveContext>(i);
}

std::vector<MandaParser::TypeAliasDeclContext *> MandaParser::CompilationUnitContext::typeAliasDecl() {
  return getRuleContexts<MandaParser::TypeAliasDeclContext>();
}

MandaParser::TypeAliasDeclContext* MandaParser::CompilationUnitContext::typeAliasDecl(size_t i) {
  return getRuleContext<MandaParser::TypeAliasDeclContext>(i);
}

std::vector<MandaParser::FuncDeclContext *> MandaParser::CompilationUnitContext::funcDecl() {
  return getRuleContexts<MandaParser::FuncDeclContext>();
}

MandaParser::FuncDeclContext* MandaParser::CompilationUnitContext::funcDecl(size_t i) {
  return getRuleContext<MandaParser::FuncDeclContext>(i);
}

std::vector<MandaParser::StmtContext *> MandaParser::CompilationUnitContext::stmt() {
  return getRuleContexts<MandaParser::StmtContext>();
}

MandaParser::StmtContext* MandaParser::CompilationUnitContext::stmt(size_t i) {
  return getRuleContext<MandaParser::StmtContext>(i);
}


size_t MandaParser::CompilationUnitContext::getRuleIndex() const {
  return MandaParser::RuleCompilationUnit;
}

antlrcpp::Any MandaParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::CompilationUnitContext* MandaParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, MandaParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::T__0) {
      setState(28);
      directive();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(37);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::T__1) {
      setState(34);
      typeAliasDecl();
      setState(39);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::T__3) {
      setState(40);
      funcDecl();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MandaParser::T__5)
      | (1ULL << MandaParser::T__17)
      | (1ULL << MandaParser::T__18)
      | (1ULL << MandaParser::T__19)
      | (1ULL << MandaParser::T__27)
      | (1ULL << MandaParser::T__28)
      | (1ULL << MandaParser::FloatLiteral)
      | (1ULL << MandaParser::HexLiteral)
      | (1ULL << MandaParser::IntegerLiteral)
      | (1ULL << MandaParser::Identifier))) != 0)) {
      setState(46);
      stmt();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectiveContext ------------------------------------------------------------------

MandaParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::ImportDirectiveContext* MandaParser::DirectiveContext::importDirective() {
  return getRuleContext<MandaParser::ImportDirectiveContext>(0);
}


size_t MandaParser::DirectiveContext::getRuleIndex() const {
  return MandaParser::RuleDirective;
}

antlrcpp::Any MandaParser::DirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitDirective(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::DirectiveContext* MandaParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 2, MandaParser::RuleDirective);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    importDirective();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDirectiveContext ------------------------------------------------------------------

MandaParser::ImportDirectiveContext::ImportDirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MandaParser::ImportDirectiveContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}


size_t MandaParser::ImportDirectiveContext::getRuleIndex() const {
  return MandaParser::RuleImportDirective;
}

antlrcpp::Any MandaParser::ImportDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitImportDirective(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ImportDirectiveContext* MandaParser::importDirective() {
  ImportDirectiveContext *_localctx = _tracker.createInstance<ImportDirectiveContext>(_ctx, getState());
  enterRule(_localctx, 4, MandaParser::RuleImportDirective);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(MandaParser::T__0);
    setState(55);
    dynamic_cast<ImportDirectiveContext *>(_localctx)->symbol = match(MandaParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAliasDeclContext ------------------------------------------------------------------

MandaParser::TypeAliasDeclContext::TypeAliasDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::TypeContext* MandaParser::TypeAliasDeclContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

tree::TerminalNode* MandaParser::TypeAliasDeclContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}


size_t MandaParser::TypeAliasDeclContext::getRuleIndex() const {
  return MandaParser::RuleTypeAliasDecl;
}

antlrcpp::Any MandaParser::TypeAliasDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTypeAliasDecl(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::TypeAliasDeclContext* MandaParser::typeAliasDecl() {
  TypeAliasDeclContext *_localctx = _tracker.createInstance<TypeAliasDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, MandaParser::RuleTypeAliasDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(MandaParser::T__1);
    setState(58);
    dynamic_cast<TypeAliasDeclContext *>(_localctx)->alias = match(MandaParser::Identifier);
    setState(59);
    match(MandaParser::T__2);
    setState(60);
    type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDeclContext ------------------------------------------------------------------

MandaParser::FuncDeclContext::FuncDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::ParameterListContext* MandaParser::FuncDeclContext::parameterList() {
  return getRuleContext<MandaParser::ParameterListContext>(0);
}

MandaParser::FunctionBodyContext* MandaParser::FuncDeclContext::functionBody() {
  return getRuleContext<MandaParser::FunctionBodyContext>(0);
}

tree::TerminalNode* MandaParser::FuncDeclContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::TypeContext* MandaParser::FuncDeclContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}


size_t MandaParser::FuncDeclContext::getRuleIndex() const {
  return MandaParser::RuleFuncDecl;
}

antlrcpp::Any MandaParser::FuncDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitFuncDecl(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::FuncDeclContext* MandaParser::funcDecl() {
  FuncDeclContext *_localctx = _tracker.createInstance<FuncDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, MandaParser::RuleFuncDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(MandaParser::T__3);
    setState(63);
    dynamic_cast<FuncDeclContext *>(_localctx)->name = match(MandaParser::Identifier);
    setState(64);
    parameterList();
    setState(65);
    match(MandaParser::T__4);
    setState(66);
    dynamic_cast<FuncDeclContext *>(_localctx)->returnType = type(0);
    setState(67);
    functionBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

MandaParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::BlockContext* MandaParser::FunctionBodyContext::block() {
  return getRuleContext<MandaParser::BlockContext>(0);
}


size_t MandaParser::FunctionBodyContext::getRuleIndex() const {
  return MandaParser::RuleFunctionBody;
}

antlrcpp::Any MandaParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::FunctionBodyContext* MandaParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 10, MandaParser::RuleFunctionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

MandaParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MandaParser::ParameterContext *> MandaParser::ParameterListContext::parameter() {
  return getRuleContexts<MandaParser::ParameterContext>();
}

MandaParser::ParameterContext* MandaParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<MandaParser::ParameterContext>(i);
}


size_t MandaParser::ParameterListContext::getRuleIndex() const {
  return MandaParser::RuleParameterList;
}

antlrcpp::Any MandaParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ParameterListContext* MandaParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, MandaParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(MandaParser::T__5);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MandaParser::T__8

    || _la == MandaParser::Identifier) {
      setState(77);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(72);
          parameter();
          setState(73);
          match(MandaParser::T__6); 
        }
        setState(79);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      }
      setState(80);
      parameter();
    }
    setState(83);
    match(MandaParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

MandaParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::TypeContext* MandaParser::ParameterContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

tree::TerminalNode* MandaParser::ParameterContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}


size_t MandaParser::ParameterContext::getRuleIndex() const {
  return MandaParser::RuleParameter;
}

antlrcpp::Any MandaParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ParameterContext* MandaParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 14, MandaParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MandaParser::T__8) {
      setState(85);
      dynamic_cast<ParameterContext *>(_localctx)->propertyKeyword = match(MandaParser::T__8);
    }
    setState(88);
    dynamic_cast<ParameterContext *>(_localctx)->name = match(MandaParser::Identifier);
    setState(89);
    match(MandaParser::T__4);
    setState(90);
    type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MandaParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::BlockContext::getRuleIndex() const {
  return MandaParser::RuleBlock;
}

void MandaParser::BlockContext::copyFrom(BlockContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EmptyBlockContext ------------------------------------------------------------------

MandaParser::EmptyBlockContext::EmptyBlockContext(BlockContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::EmptyBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitEmptyBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CurlyBlockContext ------------------------------------------------------------------

std::vector<MandaParser::StmtContext *> MandaParser::CurlyBlockContext::stmt() {
  return getRuleContexts<MandaParser::StmtContext>();
}

MandaParser::StmtContext* MandaParser::CurlyBlockContext::stmt(size_t i) {
  return getRuleContext<MandaParser::StmtContext>(i);
}

MandaParser::CurlyBlockContext::CurlyBlockContext(BlockContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::CurlyBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitCurlyBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrowBlockContext ------------------------------------------------------------------

MandaParser::ExprContext* MandaParser::ArrowBlockContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}

MandaParser::ArrowBlockContext::ArrowBlockContext(BlockContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ArrowBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitArrowBlock(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::BlockContext* MandaParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, MandaParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::T__9: {
        _localctx = dynamic_cast<BlockContext *>(_tracker.createInstance<MandaParser::ArrowBlockContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(92);
        match(MandaParser::T__9);
        setState(93);
        expr(0);
        break;
      }

      case MandaParser::T__10: {
        _localctx = dynamic_cast<BlockContext *>(_tracker.createInstance<MandaParser::EmptyBlockContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(94);
        match(MandaParser::T__10);
        break;
      }

      case MandaParser::T__11: {
        _localctx = dynamic_cast<BlockContext *>(_tracker.createInstance<MandaParser::CurlyBlockContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(95);
        match(MandaParser::T__11);
        setState(99);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MandaParser::T__5)
          | (1ULL << MandaParser::T__17)
          | (1ULL << MandaParser::T__18)
          | (1ULL << MandaParser::T__19)
          | (1ULL << MandaParser::T__27)
          | (1ULL << MandaParser::T__28)
          | (1ULL << MandaParser::FloatLiteral)
          | (1ULL << MandaParser::HexLiteral)
          | (1ULL << MandaParser::IntegerLiteral)
          | (1ULL << MandaParser::Identifier))) != 0)) {
          setState(96);
          stmt();
          setState(101);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(102);
        match(MandaParser::T__12);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MandaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::TypeContext::getRuleIndex() const {
  return MandaParser::RuleType;
}

void MandaParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnionTypeContext ------------------------------------------------------------------

std::vector<MandaParser::TypeContext *> MandaParser::UnionTypeContext::type() {
  return getRuleContexts<MandaParser::TypeContext>();
}

MandaParser::TypeContext* MandaParser::UnionTypeContext::type(size_t i) {
  return getRuleContext<MandaParser::TypeContext>(i);
}

MandaParser::UnionTypeContext::UnionTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::UnionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitUnionType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructTypeContext ------------------------------------------------------------------

std::vector<MandaParser::StructTypeMemberContext *> MandaParser::StructTypeContext::structTypeMember() {
  return getRuleContexts<MandaParser::StructTypeMemberContext>();
}

MandaParser::StructTypeMemberContext* MandaParser::StructTypeContext::structTypeMember(size_t i) {
  return getRuleContext<MandaParser::StructTypeMemberContext>(i);
}

MandaParser::StructTypeContext::StructTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenTypeContext ------------------------------------------------------------------

MandaParser::TypeContext* MandaParser::ParenTypeContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

MandaParser::ParenTypeContext::ParenTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ParenTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitParenType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdTypeContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IdTypeContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::IdTypeContext::IdTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IdTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIdType(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::TypeContext* MandaParser::type() {
   return type(0);
}

MandaParser::TypeContext* MandaParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MandaParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  MandaParser::TypeContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, MandaParser::RuleType, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::Identifier: {
        _localctx = _tracker.createInstance<IdTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(106);
        match(MandaParser::Identifier);
        break;
      }

      case MandaParser::T__11: {
        _localctx = _tracker.createInstance<StructTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(107);
        match(MandaParser::T__11);
        setState(111);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MandaParser::T__14)
          | (1ULL << MandaParser::T__15)
          | (1ULL << MandaParser::T__16)
          | (1ULL << MandaParser::Identifier))) != 0)) {
          setState(108);
          structTypeMember();
          setState(113);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(114);
        match(MandaParser::T__12);
        break;
      }

      case MandaParser::T__5: {
        _localctx = _tracker.createInstance<ParenTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(115);
        match(MandaParser::T__5);
        setState(116);
        type(0);
        setState(117);
        match(MandaParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(130);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<UnionTypeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->left = previousContext;
        pushNewRecursionContext(newContext, startState, RuleType);
        setState(121);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(123); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(122);
          match(MandaParser::T__13);
          setState(125); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MandaParser::T__13);
        setState(127);
        dynamic_cast<UnionTypeContext *>(_localctx)->right = type(3); 
      }
      setState(132);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructTypeMemberContext ------------------------------------------------------------------

MandaParser::StructTypeMemberContext::StructTypeMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::StructTypeMemberContext::getRuleIndex() const {
  return MandaParser::RuleStructTypeMember;
}

void MandaParser::StructTypeMemberContext::copyFrom(StructTypeMemberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StructTypeConstructorContext ------------------------------------------------------------------

MandaParser::ParameterListContext* MandaParser::StructTypeConstructorContext::parameterList() {
  return getRuleContext<MandaParser::ParameterListContext>(0);
}

MandaParser::FunctionBodyContext* MandaParser::StructTypeConstructorContext::functionBody() {
  return getRuleContext<MandaParser::FunctionBodyContext>(0);
}

tree::TerminalNode* MandaParser::StructTypeConstructorContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::StructTypeConstructorContext::StructTypeConstructorContext(StructTypeMemberContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructTypeConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructTypeGetterContext ------------------------------------------------------------------

MandaParser::TypeContext* MandaParser::StructTypeGetterContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

MandaParser::FunctionBodyContext* MandaParser::StructTypeGetterContext::functionBody() {
  return getRuleContext<MandaParser::FunctionBodyContext>(0);
}

tree::TerminalNode* MandaParser::StructTypeGetterContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::StructTypeGetterContext::StructTypeGetterContext(StructTypeMemberContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeGetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructTypeGetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructTypeSetterContext ------------------------------------------------------------------

MandaParser::TypeContext* MandaParser::StructTypeSetterContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

MandaParser::FunctionBodyContext* MandaParser::StructTypeSetterContext::functionBody() {
  return getRuleContext<MandaParser::FunctionBodyContext>(0);
}

tree::TerminalNode* MandaParser::StructTypeSetterContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::StructTypeSetterContext::StructTypeSetterContext(StructTypeMemberContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeSetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructTypeSetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructTypeFieldContext ------------------------------------------------------------------

MandaParser::TypeContext* MandaParser::StructTypeFieldContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

tree::TerminalNode* MandaParser::StructTypeFieldContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::StructTypeFieldContext::StructTypeFieldContext(StructTypeMemberContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructTypeField(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::StructTypeMemberContext* MandaParser::structTypeMember() {
  StructTypeMemberContext *_localctx = _tracker.createInstance<StructTypeMemberContext>(_ctx, getState());
  enterRule(_localctx, 20, MandaParser::RuleStructTypeMember);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::T__14: {
        _localctx = dynamic_cast<StructTypeMemberContext *>(_tracker.createInstance<MandaParser::StructTypeConstructorContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(133);
        match(MandaParser::T__14);
        setState(135);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MandaParser::Identifier) {
          setState(134);
          dynamic_cast<StructTypeConstructorContext *>(_localctx)->name = match(MandaParser::Identifier);
        }
        setState(137);
        parameterList();
        setState(138);
        functionBody();
        break;
      }

      case MandaParser::T__15: {
        _localctx = dynamic_cast<StructTypeMemberContext *>(_tracker.createInstance<MandaParser::StructTypeGetterContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(140);
        match(MandaParser::T__15);
        setState(141);
        dynamic_cast<StructTypeGetterContext *>(_localctx)->name = match(MandaParser::Identifier);
        setState(142);
        match(MandaParser::T__4);
        setState(143);
        type(0);
        setState(144);
        functionBody();
        break;
      }

      case MandaParser::T__16: {
        _localctx = dynamic_cast<StructTypeMemberContext *>(_tracker.createInstance<MandaParser::StructTypeSetterContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(146);
        match(MandaParser::T__16);
        setState(147);
        dynamic_cast<StructTypeSetterContext *>(_localctx)->name = match(MandaParser::Identifier);
        setState(148);
        match(MandaParser::T__4);
        setState(149);
        type(0);
        setState(150);
        functionBody();
        break;
      }

      case MandaParser::Identifier: {
        _localctx = dynamic_cast<StructTypeMemberContext *>(_tracker.createInstance<MandaParser::StructTypeFieldContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(152);
        dynamic_cast<StructTypeFieldContext *>(_localctx)->name = match(MandaParser::Identifier);
        setState(153);
        match(MandaParser::T__4);
        setState(154);
        type(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MandaParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::StmtContext::getRuleIndex() const {
  return MandaParser::RuleStmt;
}

void MandaParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

MandaParser::ExprContext* MandaParser::ExprStmtContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}

MandaParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclStmtContext ------------------------------------------------------------------

std::vector<MandaParser::VarDeclContext *> MandaParser::VarDeclStmtContext::varDecl() {
  return getRuleContexts<MandaParser::VarDeclContext>();
}

MandaParser::VarDeclContext* MandaParser::VarDeclStmtContext::varDecl(size_t i) {
  return getRuleContext<MandaParser::VarDeclContext>(i);
}

MandaParser::VarDeclStmtContext::VarDeclStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::VarDeclStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitVarDeclStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TryStmtContext ------------------------------------------------------------------

MandaParser::ExprContext* MandaParser::TryStmtContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}

MandaParser::TryStmtContext::TryStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::TryStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTryStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

MandaParser::ExprContext* MandaParser::ReturnStmtContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}

MandaParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::StmtContext* MandaParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 22, MandaParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::T__5:
      case MandaParser::T__27:
      case MandaParser::T__28:
      case MandaParser::FloatLiteral:
      case MandaParser::HexLiteral:
      case MandaParser::IntegerLiteral:
      case MandaParser::Identifier: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<MandaParser::ExprStmtContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(157);
        expr(0);
        break;
      }

      case MandaParser::T__17: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<MandaParser::VarDeclStmtContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(158);
        match(MandaParser::T__17);
        setState(164);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(159);
            varDecl();
            setState(160);
            match(MandaParser::T__6); 
          }
          setState(166);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        }
        setState(167);
        varDecl();
        break;
      }

      case MandaParser::T__18: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<MandaParser::ReturnStmtContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(168);
        match(MandaParser::T__18);
        setState(169);
        expr(0);
        break;
      }

      case MandaParser::T__19: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<MandaParser::TryStmtContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(170);
        match(MandaParser::T__19);
        setState(171);
        expr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

MandaParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MandaParser::VarDeclContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::ExprContext* MandaParser::VarDeclContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}


size_t MandaParser::VarDeclContext::getRuleIndex() const {
  return MandaParser::RuleVarDecl;
}

antlrcpp::Any MandaParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::VarDeclContext* MandaParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, MandaParser::RuleVarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(MandaParser::Identifier);
    setState(175);
    match(MandaParser::T__2);
    setState(176);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MandaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::ExprContext::getRuleIndex() const {
  return MandaParser::RuleExpr;
}

void MandaParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IntegerExprContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IntegerExprContext::IntegerLiteral() {
  return getToken(MandaParser::IntegerLiteral, 0);
}

MandaParser::IntegerExprContext::IntegerExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IntegerExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIntegerExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatExprContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::FloatExprContext::FloatLiteral() {
  return getToken(MandaParser::FloatLiteral, 0);
}

MandaParser::FloatExprContext::FloatExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::FloatExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitFloatExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueExprContext ------------------------------------------------------------------

MandaParser::TrueExprContext::TrueExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::TrueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTrueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IdentifierExprContext::Identifier() {
  return getToken(MandaParser::Identifier, 0);
}

MandaParser::IdentifierExprContext::IdentifierExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- HexExprContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::HexExprContext::HexLiteral() {
  return getToken(MandaParser::HexLiteral, 0);
}

MandaParser::HexExprContext::HexExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::HexExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitHexExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddOrSubExprContext ------------------------------------------------------------------

std::vector<MandaParser::ExprContext *> MandaParser::AddOrSubExprContext::expr() {
  return getRuleContexts<MandaParser::ExprContext>();
}

MandaParser::ExprContext* MandaParser::AddOrSubExprContext::expr(size_t i) {
  return getRuleContext<MandaParser::ExprContext>(i);
}

MandaParser::AddOrSubExprContext::AddOrSubExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::AddOrSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitAddOrSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

MandaParser::ExprContext* MandaParser::ParenExprContext::expr() {
  return getRuleContext<MandaParser::ExprContext>(0);
}

MandaParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivOrModExprContext ------------------------------------------------------------------

std::vector<MandaParser::ExprContext *> MandaParser::MulDivOrModExprContext::expr() {
  return getRuleContexts<MandaParser::ExprContext>();
}

MandaParser::ExprContext* MandaParser::MulDivOrModExprContext::expr(size_t i) {
  return getRuleContext<MandaParser::ExprContext>(i);
}

MandaParser::MulDivOrModExprContext::MulDivOrModExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::MulDivOrModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitMulDivOrModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseExprContext ------------------------------------------------------------------

MandaParser::FalseExprContext::FalseExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::FalseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitFalseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolAndOrExprContext ------------------------------------------------------------------

std::vector<MandaParser::ExprContext *> MandaParser::BoolAndOrExprContext::expr() {
  return getRuleContexts<MandaParser::ExprContext>();
}

MandaParser::ExprContext* MandaParser::BoolAndOrExprContext::expr(size_t i) {
  return getRuleContext<MandaParser::ExprContext>(i);
}

MandaParser::BoolAndOrExprContext::BoolAndOrExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::BoolAndOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitBoolAndOrExpr(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ExprContext* MandaParser::expr() {
   return expr(0);
}

MandaParser::ExprContext* MandaParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MandaParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MandaParser::ExprContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MandaParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::Identifier: {
        _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(179);
        match(MandaParser::Identifier);
        break;
      }

      case MandaParser::FloatLiteral: {
        _localctx = _tracker.createInstance<FloatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(180);
        match(MandaParser::FloatLiteral);
        break;
      }

      case MandaParser::HexLiteral: {
        _localctx = _tracker.createInstance<HexExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(181);
        match(MandaParser::HexLiteral);
        break;
      }

      case MandaParser::IntegerLiteral: {
        _localctx = _tracker.createInstance<IntegerExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(182);
        match(MandaParser::IntegerLiteral);
        break;
      }

      case MandaParser::T__27: {
        _localctx = _tracker.createInstance<TrueExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(183);
        match(MandaParser::T__27);
        break;
      }

      case MandaParser::T__28: {
        _localctx = _tracker.createInstance<FalseExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(184);
        match(MandaParser::T__28);
        break;
      }

      case MandaParser::T__5: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(185);
        match(MandaParser::T__5);
        setState(186);
        expr(0);
        setState(187);
        match(MandaParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(200);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivOrModExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(191);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(192);
          dynamic_cast<MulDivOrModExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MandaParser::T__20)
            | (1ULL << MandaParser::T__21)
            | (1ULL << MandaParser::T__22))) != 0))) {
            dynamic_cast<MulDivOrModExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(193);
          dynamic_cast<MulDivOrModExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddOrSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(195);
          dynamic_cast<AddOrSubExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MandaParser::T__23

          || _la == MandaParser::T__24)) {
            dynamic_cast<AddOrSubExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(196);
          dynamic_cast<AddOrSubExprContext *>(_localctx)->right = expr(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BoolAndOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(197);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(198);
          dynamic_cast<BoolAndOrExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MandaParser::T__25

          || _la == MandaParser::T__26)) {
            dynamic_cast<BoolAndOrExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(199);
          dynamic_cast<BoolAndOrExprContext *>(_localctx)->right = expr(5);
          break;
        }

        } 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool MandaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return typeSempred(dynamic_cast<TypeContext *>(context), predicateIndex);
    case 13: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MandaParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MandaParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MandaParser::_decisionToDFA;
atn::PredictionContextCache MandaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MandaParser::_atn;
std::vector<uint16_t> MandaParser::_serializedATN;

std::vector<std::string> MandaParser::_ruleNames = {
  "compilationUnit", "directive", "importDirective", "typeAliasDecl", "funcDecl", 
  "functionBody", "parameterList", "parameter", "block", "type", "structTypeMember", 
  "stmt", "varDecl", "expr"
};

std::vector<std::string> MandaParser::_literalNames = {
  "", "'import'", "'type'", "'='", "'func'", "':'", "'('", "','", "')'", 
  "'property'", "'=>'", "';'", "'{'", "'}'", "'|'", "'constructor'", "'get'", 
  "'set'", "'let'", "'return'", "'try'", "'*'", "'/'", "'%'", "'+'", "'-'", 
  "'&&'", "'||'", "'true'", "'false'"
};

std::vector<std::string> MandaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "Whitespace", "FloatLiteral", 
  "HexLiteral", "IntegerLiteral", "Identifier"
};

dfa::Vocabulary MandaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MandaParser::_tokenNames;

MandaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x24, 0xd0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x26, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x29, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x2c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x2f, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x35, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4e, 0xa, 0x8, 0xc, 0x8, 
    0xe, 0x8, 0x51, 0xb, 0x8, 0x3, 0x8, 0x5, 0x8, 0x54, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x5, 0x9, 0x59, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x64, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x67, 0xb, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x6a, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0x70, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x73, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7a, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x6, 0xb, 0x7e, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0x7f, 0x3, 0xb, 0x7, 
    0xb, 0x83, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x86, 0xb, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x8a, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x9e, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0xa5, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xa8, 0xb, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xaf, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0xc0, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xcb, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xce, 0xb, 0xf, 0x3, 0xf, 0x2, 0x4, 0x14, 
    0x1c, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x2, 0x5, 0x3, 0x2, 0x17, 0x19, 0x3, 0x2, 0x1a, 0x1b, 
    0x3, 0x2, 0x1c, 0x1d, 0x2, 0xe1, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x6, 0x38, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x40, 0x3, 0x2, 0x2, 0x2, 0xc, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x49, 0x3, 0x2, 0x2, 0x2, 0x10, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x69, 0x3, 0x2, 0x2, 0x2, 0x14, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x18, 0xae, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 
    0x5, 0x4, 0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x27, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x26, 0x5, 0x8, 0x5, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0xa, 0x6, 0x2, 0x2b, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0x18, 0xd, 0x2, 
    0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x5, 
    0x6, 0x4, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x3, 
    0x2, 0x2, 0x39, 0x3a, 0x7, 0x24, 0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3c, 0x7, 0x4, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x24, 0x2, 0x2, 
    0x3d, 0x3e, 0x7, 0x5, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0x14, 0xb, 0x2, 0x3f, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x6, 0x2, 0x2, 0x41, 0x42, 
    0x7, 0x24, 0x2, 0x2, 0x42, 0x43, 0x5, 0xe, 0x8, 0x2, 0x43, 0x44, 0x7, 
    0x7, 0x2, 0x2, 0x44, 0x45, 0x5, 0x14, 0xb, 0x2, 0x45, 0x46, 0x5, 0xc, 
    0x7, 0x2, 0x46, 0xb, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x5, 0x12, 0xa, 
    0x2, 0x48, 0xd, 0x3, 0x2, 0x2, 0x2, 0x49, 0x53, 0x7, 0x8, 0x2, 0x2, 
    0x4a, 0x4b, 0x5, 0x10, 0x9, 0x2, 0x4b, 0x4c, 0x7, 0x9, 0x2, 0x2, 0x4c, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x54, 0x5, 0x10, 0x9, 0x2, 0x53, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0xa, 0x2, 0x2, 0x56, 0xf, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x59, 0x7, 0xb, 0x2, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 
    0x24, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x7, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x14, 
    0xb, 0x2, 0x5d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xc, 0x2, 
    0x2, 0x5f, 0x6a, 0x5, 0x1c, 0xf, 0x2, 0x60, 0x6a, 0x7, 0xd, 0x2, 0x2, 
    0x61, 0x65, 0x7, 0xe, 0x2, 0x2, 0x62, 0x64, 0x5, 0x18, 0xd, 0x2, 0x63, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x7, 0xf, 
    0x2, 0x2, 0x69, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x69, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x61, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6c, 0x8, 0xb, 0x1, 0x2, 0x6c, 0x7a, 0x7, 0x24, 0x2, 0x2, 0x6d, 
    0x71, 0x7, 0xe, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x16, 0xc, 0x2, 0x6f, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x7a, 0x7, 0xf, 0x2, 
    0x2, 0x75, 0x76, 0x7, 0x8, 0x2, 0x2, 0x76, 0x77, 0x5, 0x14, 0xb, 0x2, 
    0x77, 0x78, 0x7, 0xa, 0x2, 0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x79, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0xc, 
    0x4, 0x2, 0x2, 0x7c, 0x7e, 0x7, 0x10, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x83, 0x5, 0x14, 0xb, 0x5, 0x82, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x15, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x89, 0x7, 0x11, 0x2, 0x2, 0x88, 0x8a, 0x7, 0x24, 
    0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0xe, 0x8, 0x2, 
    0x8c, 0x8d, 0x5, 0xc, 0x7, 0x2, 0x8d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8f, 0x7, 0x12, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x24, 0x2, 0x2, 0x90, 0x91, 
    0x7, 0x7, 0x2, 0x2, 0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92, 0x93, 0x5, 
    0xc, 0x7, 0x2, 0x93, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x13, 
    0x2, 0x2, 0x95, 0x96, 0x7, 0x24, 0x2, 0x2, 0x96, 0x97, 0x7, 0x7, 0x2, 
    0x2, 0x97, 0x98, 0x5, 0x14, 0xb, 0x2, 0x98, 0x99, 0x5, 0xc, 0x7, 0x2, 
    0x99, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x24, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x7, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x14, 0xb, 0x2, 0x9d, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xa0, 0xa6, 0x7, 0x14, 0x2, 
    0x2, 0xa1, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa2, 0xa3, 0x7, 0x9, 0x2, 0x2, 
    0xa3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xaf, 0x5, 0x1a, 0xe, 0x2, 0xaa, 0xab, 0x7, 0x15, 
    0x2, 0x2, 0xab, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xac, 0xad, 0x7, 0x16, 0x2, 
    0x2, 0xad, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xae, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
    0x7, 0x24, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x5, 0x2, 0x2, 0xb2, 0xb3, 0x5, 
    0x1c, 0xf, 0x2, 0xb3, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x8, 0xf, 
    0x1, 0x2, 0xb5, 0xc0, 0x7, 0x24, 0x2, 0x2, 0xb6, 0xc0, 0x7, 0x21, 0x2, 
    0x2, 0xb7, 0xc0, 0x7, 0x22, 0x2, 0x2, 0xb8, 0xc0, 0x7, 0x23, 0x2, 0x2, 
    0xb9, 0xc0, 0x7, 0x1e, 0x2, 0x2, 0xba, 0xc0, 0x7, 0x1f, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0x8, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x1c, 0xf, 0x2, 0xbd, 0xbe, 
    0x7, 0xa, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0xc, 0x8, 0x2, 0x2, 0xc2, 
    0xc3, 0x9, 0x2, 0x2, 0x2, 0xc3, 0xcb, 0x5, 0x1c, 0xf, 0x9, 0xc4, 0xc5, 
    0xc, 0x7, 0x2, 0x2, 0xc5, 0xc6, 0x9, 0x3, 0x2, 0x2, 0xc6, 0xcb, 0x5, 
    0x1c, 0xf, 0x8, 0xc7, 0xc8, 0xc, 0x6, 0x2, 0x2, 0xc8, 0xc9, 0x9, 0x4, 
    0x2, 0x2, 0xc9, 0xcb, 0x5, 0x1c, 0xf, 0x7, 0xca, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x21, 0x27, 0x2d, 0x33, 0x4f, 0x53, 0x58, 
    0x65, 0x69, 0x71, 0x79, 0x7f, 0x84, 0x89, 0x9d, 0xa6, 0xae, 0xbf, 0xca, 
    0xcc, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MandaParser::Initializer MandaParser::_init;
