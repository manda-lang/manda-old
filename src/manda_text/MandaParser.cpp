
// Generated from /Users/thosakwe/Source/Compilers/manda/src/manda_text/Manda.g4 by ANTLR 4.7


#include "MandaVisitor.h"

#include "MandaParser.h"


using namespace antlrcpp;
using namespace manda_text;
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


//----------------- ProgramContext ------------------------------------------------------------------

MandaParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MandaParser::DirectiveContext *> MandaParser::ProgramContext::directive() {
  return getRuleContexts<MandaParser::DirectiveContext>();
}

MandaParser::DirectiveContext* MandaParser::ProgramContext::directive(size_t i) {
  return getRuleContext<MandaParser::DirectiveContext>(i);
}

std::vector<MandaParser::StatementContext *> MandaParser::ProgramContext::statement() {
  return getRuleContexts<MandaParser::StatementContext>();
}

MandaParser::StatementContext* MandaParser::ProgramContext::statement(size_t i) {
  return getRuleContext<MandaParser::StatementContext>(i);
}

std::vector<MandaParser::CommentContext *> MandaParser::ProgramContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::ProgramContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}


size_t MandaParser::ProgramContext::getRuleIndex() const {
  return MandaParser::RuleProgram;
}

antlrcpp::Any MandaParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ProgramContext* MandaParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MandaParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(35);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(32);
        directive(); 
      }
      setState(37);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(38);
        statement(); 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(44);
      comment();
      setState(49);
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

//----------------- CommentContext ------------------------------------------------------------------

MandaParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::CommentContext::getRuleIndex() const {
  return MandaParser::RuleComment;
}

void MandaParser::CommentContext::copyFrom(CommentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DocCommentContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::DocCommentContext::DOC_COMMENT() {
  return getToken(MandaParser::DOC_COMMENT, 0);
}

MandaParser::DocCommentContext::DocCommentContext(CommentContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::DocCommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitDocComment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SingleLineCommentContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::SingleLineCommentContext::SINGLE_LINE_COMMENT() {
  return getToken(MandaParser::SINGLE_LINE_COMMENT, 0);
}

MandaParser::SingleLineCommentContext::SingleLineCommentContext(CommentContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::SingleLineCommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitSingleLineComment(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::CommentContext* MandaParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 2, MandaParser::RuleComment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::DOC_COMMENT: {
        _localctx = dynamic_cast<CommentContext *>(_tracker.createInstance<MandaParser::DocCommentContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(50);
        match(MandaParser::DOC_COMMENT);
        break;
      }

      case MandaParser::SINGLE_LINE_COMMENT: {
        _localctx = dynamic_cast<CommentContext *>(_tracker.createInstance<MandaParser::SingleLineCommentContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(51);
        match(MandaParser::SINGLE_LINE_COMMENT);
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

//----------------- DirectiveContext ------------------------------------------------------------------

MandaParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::DirectiveContext::getRuleIndex() const {
  return MandaParser::RuleDirective;
}

void MandaParser::DirectiveContext::copyFrom(DirectiveContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ImportDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::ImportDirectiveContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::ImportDirectiveContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::ImportDirectiveContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::ImportDirectiveContext::ImportDirectiveContext(DirectiveContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ImportDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitImportDirective(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WithDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::WithDirectiveContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::WithDirectiveContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::WithDirectiveContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::WithDirectiveContext::WithDirectiveContext(DirectiveContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::WithDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitWithDirective(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypedefDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::TypedefDirectiveContext::ID() {
  return getToken(MandaParser::ID, 0);
}

MandaParser::TypeContext* MandaParser::TypedefDirectiveContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::TypedefDirectiveContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::TypedefDirectiveContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::TypedefDirectiveContext::TypedefDirectiveContext(DirectiveContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::TypedefDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTypedefDirective(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::DirectiveContext* MandaParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 4, MandaParser::RuleDirective);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<MandaParser::ImportDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(54);
        comment();
        setState(59);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(60);
      match(MandaParser::T__0);
      setState(61);
      match(MandaParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<MandaParser::WithDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(62);
        comment();
        setState(67);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(68);
      match(MandaParser::T__1);
      setState(69);
      match(MandaParser::ID);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<MandaParser::TypedefDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(70);
        comment();
        setState(75);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(76);
      match(MandaParser::T__2);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(77);
        comment();
        setState(82);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(83);
      match(MandaParser::ID);
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(84);
        comment();
        setState(89);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(90);
      match(MandaParser::T__3);
      setState(91);
      type(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MandaParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::StatementContext::getRuleIndex() const {
  return MandaParser::RuleStatement;
}

void MandaParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

MandaParser::ExpressionContext* MandaParser::ExpressionStatementContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

MandaParser::ExpressionStatementContext::ExpressionStatementContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStatementContext ------------------------------------------------------------------

MandaParser::ExpressionContext* MandaParser::ReturnStatementContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::ReturnStatementContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::ReturnStatementContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::ReturnStatementContext::ReturnStatementContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableDeclarationStatementContext ------------------------------------------------------------------

MandaParser::VariableModifierContext* MandaParser::VariableDeclarationStatementContext::variableModifier() {
  return getRuleContext<MandaParser::VariableModifierContext>(0);
}

tree::TerminalNode* MandaParser::VariableDeclarationStatementContext::ID() {
  return getToken(MandaParser::ID, 0);
}

MandaParser::ExpressionContext* MandaParser::VariableDeclarationStatementContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::VariableDeclarationStatementContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::VariableDeclarationStatementContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::TypeAnnotationContext* MandaParser::VariableDeclarationStatementContext::typeAnnotation() {
  return getRuleContext<MandaParser::TypeAnnotationContext>(0);
}

MandaParser::VariableDeclarationStatementContext::VariableDeclarationStatementContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::VariableDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::StatementContext* MandaParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, MandaParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MandaParser::ExpressionStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(94);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MandaParser::ReturnStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(95);
        comment();
        setState(100);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(101);
      match(MandaParser::T__4);
      setState(102);
      expression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MandaParser::VariableDeclarationStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(103);
      variableModifier();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(104);
        comment();
        setState(109);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(110);
      match(MandaParser::ID);
      setState(112);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(111);
        typeAnnotation();
        break;
      }

      }
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(114);
        comment();
        setState(119);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(120);
      match(MandaParser::T__3);
      setState(121);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableModifierContext ------------------------------------------------------------------

MandaParser::VariableModifierContext::VariableModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::VariableModifierContext::getRuleIndex() const {
  return MandaParser::RuleVariableModifier;
}

void MandaParser::VariableModifierContext::copyFrom(VariableModifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarModifierContext ------------------------------------------------------------------

std::vector<MandaParser::CommentContext *> MandaParser::VarModifierContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::VarModifierContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::VarModifierContext::VarModifierContext(VariableModifierContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::VarModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitVarModifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LetModifierContext ------------------------------------------------------------------

std::vector<MandaParser::CommentContext *> MandaParser::LetModifierContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::LetModifierContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::LetModifierContext::LetModifierContext(VariableModifierContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::LetModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitLetModifier(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::VariableModifierContext* MandaParser::variableModifier() {
  VariableModifierContext *_localctx = _tracker.createInstance<VariableModifierContext>(_ctx, getState());
  enterRule(_localctx, 8, MandaParser::RuleVariableModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariableModifierContext *>(_tracker.createInstance<MandaParser::LetModifierContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(125);
        comment();
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(131);
      match(MandaParser::T__5);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariableModifierContext *>(_tracker.createInstance<MandaParser::VarModifierContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(135);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(132);
        comment();
        setState(137);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(138);
      match(MandaParser::T__6);
      break;
    }

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

std::vector<MandaParser::CommentContext *> MandaParser::UnionTypeContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::UnionTypeContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::UnionTypeContext::UnionTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::UnionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitUnionType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructTypeContext ------------------------------------------------------------------

std::vector<MandaParser::CommentContext *> MandaParser::StructTypeContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::StructTypeContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

std::vector<MandaParser::StructTypeFieldContext *> MandaParser::StructTypeContext::structTypeField() {
  return getRuleContexts<MandaParser::StructTypeFieldContext>();
}

MandaParser::StructTypeFieldContext* MandaParser::StructTypeContext::structTypeField(size_t i) {
  return getRuleContext<MandaParser::StructTypeFieldContext>(i);
}

MandaParser::StructTypeContext::StructTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StructTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedTypeContext ------------------------------------------------------------------

MandaParser::TypeContext* MandaParser::ParenthesizedTypeContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::ParenthesizedTypeContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::ParenthesizedTypeContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::ParenthesizedTypeContext::ParenthesizedTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ParenthesizedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitParenthesizedType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierTypeContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IdentifierTypeContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::IdentifierTypeContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::IdentifierTypeContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::TypeParameterListContext* MandaParser::IdentifierTypeContext::typeParameterList() {
  return getRuleContext<MandaParser::TypeParameterListContext>(0);
}

MandaParser::IdentifierTypeContext::IdentifierTypeContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IdentifierTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIdentifierType(this);
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, MandaParser::RuleType, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IdentifierTypeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(142);
        comment();
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(148);
      match(MandaParser::ID);
      setState(150);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(149);
        typeParameterList();
        break;
      }

      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<StructTypeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(152);
        comment();
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(158);
      match(MandaParser::T__8);
      setState(174);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(170);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(159);
            structTypeField();
            setState(163);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == MandaParser::DOC_COMMENT

            || _la == MandaParser::SINGLE_LINE_COMMENT) {
              setState(160);
              comment();
              setState(165);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(166);
            match(MandaParser::T__9); 
          }
          setState(172);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
        }
        setState(173);
        structTypeField();
        break;
      }

      }
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(176);
        comment();
        setState(181);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(182);
      match(MandaParser::T__10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParenthesizedTypeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(183);
        comment();
        setState(188);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(189);
      match(MandaParser::T__11);
      setState(190);
      type(0);
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(191);
        comment();
        setState(196);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(197);
      match(MandaParser::T__12);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<UnionTypeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleType);
        setState(201);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(205);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MandaParser::DOC_COMMENT

        || _la == MandaParser::SINGLE_LINE_COMMENT) {
          setState(202);
          comment();
          setState(207);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(208);
        match(MandaParser::T__7);
        setState(209);
        type(4); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructTypeFieldContext ------------------------------------------------------------------

MandaParser::StructTypeFieldContext::StructTypeFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MandaParser::StructTypeFieldContext::ID() {
  return getToken(MandaParser::ID, 0);
}

MandaParser::TypeContext* MandaParser::StructTypeFieldContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::StructTypeFieldContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::StructTypeFieldContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}


size_t MandaParser::StructTypeFieldContext::getRuleIndex() const {
  return MandaParser::RuleStructTypeField;
}

antlrcpp::Any MandaParser::StructTypeFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStructTypeField(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::StructTypeFieldContext* MandaParser::structTypeField() {
  StructTypeFieldContext *_localctx = _tracker.createInstance<StructTypeFieldContext>(_ctx, getState());
  enterRule(_localctx, 12, MandaParser::RuleStructTypeField);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(215);
      comment();
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(221);
    match(MandaParser::ID);
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(222);
      comment();
      setState(227);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(228);
    match(MandaParser::T__13);
    setState(229);
    type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAnnotationContext ------------------------------------------------------------------

MandaParser::TypeAnnotationContext::TypeAnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MandaParser::TypeContext* MandaParser::TypeAnnotationContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::TypeAnnotationContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::TypeAnnotationContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}


size_t MandaParser::TypeAnnotationContext::getRuleIndex() const {
  return MandaParser::RuleTypeAnnotation;
}

antlrcpp::Any MandaParser::TypeAnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTypeAnnotation(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::TypeAnnotationContext* MandaParser::typeAnnotation() {
  TypeAnnotationContext *_localctx = _tracker.createInstance<TypeAnnotationContext>(_ctx, getState());
  enterRule(_localctx, 14, MandaParser::RuleTypeAnnotation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(231);
      comment();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    match(MandaParser::T__13);
    setState(238);
    type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParameterContext ------------------------------------------------------------------

MandaParser::TypeParameterContext::TypeParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::TypeParameterContext::getRuleIndex() const {
  return MandaParser::RuleTypeParameter;
}

void MandaParser::TypeParameterContext::copyFrom(TypeParameterContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentifierTypeParameterContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IdentifierTypeParameterContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::IdentifierTypeParameterContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::IdentifierTypeParameterContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::IdentifierTypeParameterContext::IdentifierTypeParameterContext(TypeParameterContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IdentifierTypeParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIdentifierTypeParameter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExtendsTypeParameterContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::ExtendsTypeParameterContext::ID() {
  return getToken(MandaParser::ID, 0);
}

MandaParser::TypeContext* MandaParser::ExtendsTypeParameterContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::ExtendsTypeParameterContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::ExtendsTypeParameterContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::ExtendsTypeParameterContext::ExtendsTypeParameterContext(TypeParameterContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::ExtendsTypeParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitExtendsTypeParameter(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::TypeParameterContext* MandaParser::typeParameter() {
  TypeParameterContext *_localctx = _tracker.createInstance<TypeParameterContext>(_ctx, getState());
  enterRule(_localctx, 16, MandaParser::RuleTypeParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<TypeParameterContext *>(_tracker.createInstance<MandaParser::IdentifierTypeParameterContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(240);
        comment();
        setState(245);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(246);
      match(MandaParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<TypeParameterContext *>(_tracker.createInstance<MandaParser::ExtendsTypeParameterContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(247);
        comment();
        setState(252);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      match(MandaParser::ID);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(254);
        comment();
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(260);
      match(MandaParser::T__14);
      setState(261);
      type(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParameterListContext ------------------------------------------------------------------

MandaParser::TypeParameterListContext::TypeParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MandaParser::TypeParameterContext *> MandaParser::TypeParameterListContext::typeParameter() {
  return getRuleContexts<MandaParser::TypeParameterContext>();
}

MandaParser::TypeParameterContext* MandaParser::TypeParameterListContext::typeParameter(size_t i) {
  return getRuleContext<MandaParser::TypeParameterContext>(i);
}

std::vector<MandaParser::CommentContext *> MandaParser::TypeParameterListContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::TypeParameterListContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}


size_t MandaParser::TypeParameterListContext::getRuleIndex() const {
  return MandaParser::RuleTypeParameterList;
}

antlrcpp::Any MandaParser::TypeParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTypeParameterList(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::TypeParameterListContext* MandaParser::typeParameterList() {
  TypeParameterListContext *_localctx = _tracker.createInstance<TypeParameterListContext>(_ctx, getState());
  enterRule(_localctx, 18, MandaParser::RuleTypeParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(264);
      comment();
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(270);
    match(MandaParser::T__15);

    setState(282);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(271);
        typeParameter();
        setState(275);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MandaParser::DOC_COMMENT

        || _la == MandaParser::SINGLE_LINE_COMMENT) {
          setState(272);
          comment();
          setState(277);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(278);
        match(MandaParser::T__9); 
      }
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(285);
    typeParameter();
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(287);
      comment();
      setState(292);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(293);
    match(MandaParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentListContext ------------------------------------------------------------------

MandaParser::TypeArgumentListContext::TypeArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MandaParser::TypeContext *> MandaParser::TypeArgumentListContext::type() {
  return getRuleContexts<MandaParser::TypeContext>();
}

MandaParser::TypeContext* MandaParser::TypeArgumentListContext::type(size_t i) {
  return getRuleContext<MandaParser::TypeContext>(i);
}


size_t MandaParser::TypeArgumentListContext::getRuleIndex() const {
  return MandaParser::RuleTypeArgumentList;
}

antlrcpp::Any MandaParser::TypeArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitTypeArgumentList(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::TypeArgumentListContext* MandaParser::typeArgumentList() {
  TypeArgumentListContext *_localctx = _tracker.createInstance<TypeArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 20, MandaParser::RuleTypeArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(MandaParser::T__15);
    setState(305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MandaParser::T__8)
      | (1ULL << MandaParser::T__11)
      | (1ULL << MandaParser::DOC_COMMENT)
      | (1ULL << MandaParser::SINGLE_LINE_COMMENT)
      | (1ULL << MandaParser::ID))) != 0)) {
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(296);
          type(0);
          setState(297);
          match(MandaParser::T__9); 
        }
        setState(303);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      }
      setState(304);
      type(0);
    }
    setState(307);
    match(MandaParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

MandaParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::ArgumentListContext::getRuleIndex() const {
  return MandaParser::RuleArgumentList;
}

void MandaParser::ArgumentListContext::copyFrom(ArgumentListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MixedParameterListContext ------------------------------------------------------------------

std::vector<MandaParser::ExpressionContext *> MandaParser::MixedParameterListContext::expression() {
  return getRuleContexts<MandaParser::ExpressionContext>();
}

MandaParser::ExpressionContext* MandaParser::MixedParameterListContext::expression(size_t i) {
  return getRuleContext<MandaParser::ExpressionContext>(i);
}

std::vector<MandaParser::NamedArgumentContext *> MandaParser::MixedParameterListContext::namedArgument() {
  return getRuleContexts<MandaParser::NamedArgumentContext>();
}

MandaParser::NamedArgumentContext* MandaParser::MixedParameterListContext::namedArgument(size_t i) {
  return getRuleContext<MandaParser::NamedArgumentContext>(i);
}

std::vector<MandaParser::CommentContext *> MandaParser::MixedParameterListContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::MixedParameterListContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::MixedParameterListContext::MixedParameterListContext(ArgumentListContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::MixedParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitMixedParameterList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NamedParameterListContext ------------------------------------------------------------------

std::vector<MandaParser::NamedArgumentContext *> MandaParser::NamedParameterListContext::namedArgument() {
  return getRuleContexts<MandaParser::NamedArgumentContext>();
}

MandaParser::NamedArgumentContext* MandaParser::NamedParameterListContext::namedArgument(size_t i) {
  return getRuleContext<MandaParser::NamedArgumentContext>(i);
}

std::vector<MandaParser::CommentContext *> MandaParser::NamedParameterListContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::NamedParameterListContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::NamedParameterListContext::NamedParameterListContext(ArgumentListContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::NamedParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitNamedParameterList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositionalParameterListContext ------------------------------------------------------------------

std::vector<MandaParser::CommentContext *> MandaParser::PositionalParameterListContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::PositionalParameterListContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

std::vector<MandaParser::ExpressionContext *> MandaParser::PositionalParameterListContext::expression() {
  return getRuleContexts<MandaParser::ExpressionContext>();
}

MandaParser::ExpressionContext* MandaParser::PositionalParameterListContext::expression(size_t i) {
  return getRuleContext<MandaParser::ExpressionContext>(i);
}

MandaParser::PositionalParameterListContext::PositionalParameterListContext(ArgumentListContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::PositionalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitPositionalParameterList(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::ArgumentListContext* MandaParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 22, MandaParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(425);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ArgumentListContext *>(_tracker.createInstance<MandaParser::PositionalParameterListContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(309);
        comment();
        setState(314);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(315);
      match(MandaParser::T__11);
      setState(331);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
      case 1: {
        setState(327);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(316);
            expression(0);
            setState(320);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == MandaParser::DOC_COMMENT

            || _la == MandaParser::SINGLE_LINE_COMMENT) {
              setState(317);
              comment();
              setState(322);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(323);
            match(MandaParser::T__9); 
          }
          setState(329);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        }
        setState(330);
        expression(0);
        break;
      }

      }
      setState(336);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(333);
        comment();
        setState(338);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(339);
      match(MandaParser::T__12);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ArgumentListContext *>(_tracker.createInstance<MandaParser::NamedParameterListContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(343);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(340);
        comment();
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(346);
      match(MandaParser::T__11);

      setState(358);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(347);
          namedArgument();
          setState(351);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(348);
            comment();
            setState(353);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(354);
          match(MandaParser::T__9); 
        }
        setState(360);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      }
      setState(361);
      namedArgument();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(363);
        comment();
        setState(368);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(369);
      match(MandaParser::T__12);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ArgumentListContext *>(_tracker.createInstance<MandaParser::MixedParameterListContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(371);
        comment();
        setState(376);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(377);
      match(MandaParser::T__11);

      setState(389);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(378);
          expression(0);
          setState(382);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(379);
            comment();
            setState(384);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(385);
          match(MandaParser::T__9); 
        }
        setState(391);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      }
      setState(392);
      expression(0);
      setState(397);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(394);
        comment();
        setState(399);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(400);
      match(MandaParser::T__9);

      setState(412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(401);
          namedArgument();
          setState(405);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(402);
            comment();
            setState(407);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(408);
          match(MandaParser::T__9); 
        }
        setState(414);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(415);
      namedArgument();
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(417);
        comment();
        setState(422);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(423);
      match(MandaParser::T__12);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedArgumentContext ------------------------------------------------------------------

MandaParser::NamedArgumentContext::NamedArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MandaParser::NamedArgumentContext::ID() {
  return getToken(MandaParser::ID, 0);
}

MandaParser::ExpressionContext* MandaParser::NamedArgumentContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::NamedArgumentContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::NamedArgumentContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}


size_t MandaParser::NamedArgumentContext::getRuleIndex() const {
  return MandaParser::RuleNamedArgument;
}

antlrcpp::Any MandaParser::NamedArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitNamedArgument(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::NamedArgumentContext* MandaParser::namedArgument() {
  NamedArgumentContext *_localctx = _tracker.createInstance<NamedArgumentContext>(_ctx, getState());
  enterRule(_localctx, 24, MandaParser::RuleNamedArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(427);
      comment();
      setState(432);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(433);
    match(MandaParser::ID);
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MandaParser::DOC_COMMENT

    || _la == MandaParser::SINGLE_LINE_COMMENT) {
      setState(434);
      comment();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(440);
    match(MandaParser::T__13);
    setState(441);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MandaParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::ExpressionContext::getRuleIndex() const {
  return MandaParser::RuleExpression;
}

void MandaParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MemberExpressionContext ------------------------------------------------------------------

MandaParser::ExpressionContext* MandaParser::MemberExpressionContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

tree::TerminalNode* MandaParser::MemberExpressionContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::MemberExpressionContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::MemberExpressionContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::MemberExpressionContext::MemberExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::MemberExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitMemberExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

MandaParser::LiteralContext* MandaParser::LiteralExpressionContext::literal() {
  return getRuleContext<MandaParser::LiteralContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::LiteralExpressionContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::LiteralExpressionContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::LiteralExpressionContext::LiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExpressionContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::IdExpressionContext::ID() {
  return getToken(MandaParser::ID, 0);
}

std::vector<MandaParser::CommentContext *> MandaParser::IdExpressionContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::IdExpressionContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::IdExpressionContext::IdExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::IdExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitIdExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExpressionContext ------------------------------------------------------------------

MandaParser::ArgumentListContext* MandaParser::CallExpressionContext::argumentList() {
  return getRuleContext<MandaParser::ArgumentListContext>(0);
}

MandaParser::ExpressionContext* MandaParser::CallExpressionContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

MandaParser::TypeArgumentListContext* MandaParser::CallExpressionContext::typeArgumentList() {
  return getRuleContext<MandaParser::TypeArgumentListContext>(0);
}

MandaParser::CallExpressionContext::CallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::CallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitCallExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsExpressionContext ------------------------------------------------------------------

MandaParser::ExpressionContext* MandaParser::AsExpressionContext::expression() {
  return getRuleContext<MandaParser::ExpressionContext>(0);
}

MandaParser::TypeContext* MandaParser::AsExpressionContext::type() {
  return getRuleContext<MandaParser::TypeContext>(0);
}

std::vector<MandaParser::CommentContext *> MandaParser::AsExpressionContext::comment() {
  return getRuleContexts<MandaParser::CommentContext>();
}

MandaParser::CommentContext* MandaParser::AsExpressionContext::comment(size_t i) {
  return getRuleContext<MandaParser::CommentContext>(i);
}

MandaParser::AsExpressionContext::AsExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::AsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitAsExpression(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::ExpressionContext* MandaParser::expression() {
   return expression(0);
}

MandaParser::ExpressionContext* MandaParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MandaParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MandaParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MandaParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(458);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IdExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(447);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(444);
        comment();
        setState(449);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(450);
      match(MandaParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(454);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MandaParser::DOC_COMMENT

      || _la == MandaParser::SINGLE_LINE_COMMENT) {
        setState(451);
        comment();
        setState(456);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(457);
      literal();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(497);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(495);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MemberExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(460);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(464);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(461);
            comment();
            setState(466);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(467);
          match(MandaParser::T__17);
          setState(471);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(468);
            comment();
            setState(473);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(474);
          match(MandaParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<CallExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->target = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(475);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(477);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == MandaParser::T__15) {
            setState(476);
            typeArgumentList();
          }
          setState(479);
          argumentList();
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AsExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(480);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(484);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MandaParser::DOC_COMMENT

          || _la == MandaParser::SINGLE_LINE_COMMENT) {
            setState(481);
            comment();
            setState(486);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(487);
          match(MandaParser::T__18);
          setState(491);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(488);
              comment(); 
            }
            setState(493);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
          }
          setState(494);
          type(0);
          break;
        }

        } 
      }
      setState(499);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MandaParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MandaParser::LiteralContext::getRuleIndex() const {
  return MandaParser::RuleLiteral;
}

void MandaParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::BinaryLiteralContext::BINARY() {
  return getToken(MandaParser::BINARY, 0);
}

MandaParser::BinaryLiteralContext::BinaryLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::BinaryLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitBinaryLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

MandaParser::StringContext* MandaParser::StringLiteralContext::string() {
  return getRuleContext<MandaParser::StringContext>(0);
}

MandaParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OctalLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::OctalLiteralContext::OCTAL() {
  return getToken(MandaParser::OCTAL, 0);
}

MandaParser::OctalLiteralContext::OctalLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::OctalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitOctalLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecimalLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::DecimalLiteralContext::DECIMAL() {
  return getToken(MandaParser::DECIMAL, 0);
}

MandaParser::DecimalLiteralContext::DecimalLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::DecimalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitDecimalLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- HexLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MandaParser::HexLiteralContext::HEX() {
  return getToken(MandaParser::HEX, 0);
}

MandaParser::HexLiteralContext::HexLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MandaParser::HexLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitHexLiteral(this);
  else
    return visitor->visitChildren(this);
}
MandaParser::LiteralContext* MandaParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 28, MandaParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(505);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MandaParser::T__19:
      case MandaParser::SINGLE_QUOTED_STRING: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MandaParser::StringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(500);
        string();
        break;
      }

      case MandaParser::DECIMAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MandaParser::DecimalLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(501);
        match(MandaParser::DECIMAL);
        break;
      }

      case MandaParser::BINARY: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MandaParser::BinaryLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(502);
        match(MandaParser::BINARY);
        break;
      }

      case MandaParser::HEX: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MandaParser::HexLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(503);
        match(MandaParser::HEX);
        break;
      }

      case MandaParser::OCTAL: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MandaParser::OctalLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(504);
        match(MandaParser::OCTAL);
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

//----------------- StringContext ------------------------------------------------------------------

MandaParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MandaParser::StringContext::SINGLE_QUOTED_STRING() {
  return getToken(MandaParser::SINGLE_QUOTED_STRING, 0);
}


size_t MandaParser::StringContext::getRuleIndex() const {
  return MandaParser::RuleString;
}

antlrcpp::Any MandaParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MandaVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

MandaParser::StringContext* MandaParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 30, MandaParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(508);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MandaParser::T__19) {
      setState(507);
      match(MandaParser::T__19);
    }
    setState(510);
    match(MandaParser::SINGLE_QUOTED_STRING);
   
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
    case 5: return typeSempred(dynamic_cast<TypeContext *>(context), predicateIndex);
    case 13: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MandaParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool MandaParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

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
  "program", "comment", "directive", "statement", "variableModifier", "type", 
  "structTypeField", "typeAnnotation", "typeParameter", "typeParameterList", 
  "typeArgumentList", "argumentList", "namedArgument", "expression", "literal", 
  "string"
};

std::vector<std::string> MandaParser::_literalNames = {
  "", "'import'", "'with'", "'type'", "'='", "'return'", "'let'", "'var'", 
  "'|'", "'{'", "','", "'}'", "'('", "')'", "':'", "'extends'", "'<'", "'>'", 
  "'.'", "'as'", "'r'"
};

std::vector<std::string> MandaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "WS", "DOC_COMMENT", "SINGLE_LINE_COMMENT", "SINGLE_QUOTED_STRING", 
  "DECIMAL", "BINARY", "HEX", "OCTAL", "ID"
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
    0x3, 0x1f, 0x203, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 
    0x2, 0x7, 0x2, 0x24, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x27, 0xb, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x2a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2d, 0xb, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x30, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x33, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x37, 0xa, 0x3, 0x3, 0x4, 0x7, 0x4, 0x3a, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x3d, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x42, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x45, 0xb, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4a, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x4d, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x51, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x54, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x58, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x5b, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5f, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x63, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x66, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x6c, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x6f, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x73, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x76, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x79, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x7e, 0xa, 
    0x5, 0x3, 0x6, 0x7, 0x6, 0x81, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x84, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x88, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x8b, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x8e, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x92, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x95, 0xb, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x99, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0x9c, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x9f, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0xa4, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xa7, 0xb, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0xab, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xae, 0xb, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xb1, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0xb4, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0xb7, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xbb, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0xbe, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0xc3, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xc6, 0xb, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0xca, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xce, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xd1, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0xd5, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xd8, 0xb, 0x7, 0x3, 0x8, 0x7, 
    0x8, 0xdb, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xde, 0xb, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0xe2, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xe5, 0xb, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x7, 0x9, 0xeb, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0xee, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x7, 
    0xa, 0xf4, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xf7, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0xfb, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xfe, 0xb, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0x102, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x105, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x109, 0xa, 0xa, 0x3, 0xb, 0x7, 
    0xb, 0x10c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x10f, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x114, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x117, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x11b, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x11e, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x123, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x126, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x12e, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x131, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x134, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xd, 0x7, 0xd, 0x139, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0x13c, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x141, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x144, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x148, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x14b, 0xb, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x14e, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0x151, 0xa, 0xd, 0xc, 0xd, 
    0xe, 0xd, 0x154, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x158, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x15b, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x7, 0xd, 0x160, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x163, 0xb, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x167, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x16a, 
    0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x16f, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0x172, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x177, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x17a, 0xb, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x17f, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x182, 
    0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x186, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0x189, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x18e, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x191, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x7, 0xd, 0x196, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x199, 0xb, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x19d, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x1a0, 
    0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x1a5, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0x1a8, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x1ac, 
    0xa, 0xd, 0x3, 0xe, 0x7, 0xe, 0x1af, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x1b2, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x1b6, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0x1b9, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0x1c0, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1c3, 0xb, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0x1c7, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1ca, 
    0xb, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1cd, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x1d1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1d4, 0xb, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0x1d8, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1db, 0xb, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1e0, 0xa, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1e5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1e8, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1ec, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0x1ef, 0xb, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1f2, 0xa, 0xf, 0xc, 0xf, 
    0xe, 0xf, 0x1f5, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x1fc, 0xa, 0x10, 0x3, 0x11, 0x5, 0x11, 0x1ff, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 0x4, 0xc, 0x1c, 0x12, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x2, 0x2, 0x2, 0x244, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x36, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xc, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x10, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x108, 0x3, 0x2, 0x2, 0x2, 0x14, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x129, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x22, 0x24, 0x5, 
    0x6, 0x4, 0x2, 0x23, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x7, 0x18, 0x2, 0x2, 0x35, 
    0x37, 0x7, 0x19, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x5, 
    0x4, 0x3, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x3f, 0x5f, 0x7, 0x1f, 0x2, 0x2, 0x40, 
    0x42, 0x5, 0x4, 0x3, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x47, 0x7, 0x4, 0x2, 0x2, 0x47, 0x5f, 0x7, 0x1f, 0x2, 
    0x2, 0x48, 0x4a, 0x5, 0x4, 0x3, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x52, 0x7, 0x5, 0x2, 0x2, 0x4f, 0x51, 0x5, 
    0x4, 0x3, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x59, 0x7, 0x1f, 0x2, 0x2, 0x56, 0x58, 0x5, 0x4, 0x3, 0x2, 0x57, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x6, 
    0x2, 0x2, 0x5d, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x5e, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x60, 0x7e, 0x5, 0x1c, 0xf, 0x2, 0x61, 
    0x63, 0x5, 0x4, 0x3, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x68, 0x7, 0x7, 0x2, 0x2, 0x68, 0x7e, 0x5, 0x1c, 0xf, 
    0x2, 0x69, 0x6d, 0x5, 0xa, 0x6, 0x2, 0x6a, 0x6c, 0x5, 0x4, 0x3, 0x2, 
    0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x72, 0x7, 
    0x1f, 0x2, 0x2, 0x71, 0x73, 0x5, 0x10, 0x9, 0x2, 0x72, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x76, 0x5, 0x4, 0x3, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x79, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x6, 0x2, 0x2, 0x7b, 0x7c, 0x5, 
    0x1c, 0xf, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x64, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x4, 0x3, 0x2, 
    0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x8e, 0x7, 
    0x8, 0x2, 0x2, 0x86, 0x88, 0x5, 0x4, 0x3, 0x2, 0x87, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x7, 0x9, 0x2, 0x2, 0x8d, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8e, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x8f, 0x93, 0x8, 0x7, 0x1, 0x2, 0x90, 0x92, 0x5, 
    0x4, 0x3, 0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x96, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x98, 0x7, 0x1f, 0x2, 0x2, 0x97, 0x99, 0x5, 0x14, 0xb, 0x2, 0x98, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x4, 0x3, 0x2, 0x9b, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xb0, 0x7, 0xb, 0x2, 0x2, 
    0xa1, 0xa5, 0x5, 0xe, 0x8, 0x2, 0xa2, 0xa4, 0x5, 0x4, 0x3, 0x2, 0xa3, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0xc, 
    0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb1, 0x5, 0xe, 0x8, 0x2, 0xb0, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x4, 0x3, 0x2, 0xb3, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xca, 0x7, 0xd, 0x2, 0x2, 0xb9, 
    0xbb, 0x5, 0x4, 0x3, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc0, 0x7, 0xe, 0x2, 0x2, 0xc0, 0xc4, 0x5, 0xc, 0x7, 
    0x2, 0xc1, 0xc3, 0x5, 0x4, 0x3, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0xf, 0x2, 0x2, 0xc8, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xca, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xcf, 0xc, 0x5, 0x2, 0x2, 0xcc, 0xce, 0x5, 0x4, 0x3, 0x2, 
    0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 
    0xa, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0xc, 0x7, 0x6, 0xd4, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x4, 0x3, 0x2, 0xda, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe3, 0x7, 0x1f, 
    0x2, 0x2, 0xe0, 0xe2, 0x5, 0x4, 0x3, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0xe2, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x10, 0x2, 0x2, 0xe7, 0xe8, 
    0x5, 0xc, 0x7, 0x2, 0xe8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x5, 
    0x4, 0x3, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xf0, 0x7, 0x10, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0xc, 0x7, 0x2, 0xf1, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x4, 0x3, 0x2, 0xf3, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x109, 0x7, 0x1f, 0x2, 
    0x2, 0xf9, 0xfb, 0x5, 0x4, 0x3, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x103, 0x7, 0x1f, 0x2, 0x2, 0x100, 0x102, 
    0x5, 0x4, 0x3, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x7, 0x11, 0x2, 0x2, 0x107, 0x109, 
    0x5, 0xc, 0x7, 0x2, 0x108, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x108, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x13, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x4, 
    0x3, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x10e, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x11c, 0x7, 0x12, 0x2, 0x2, 0x111, 0x115, 0x5, 0x12, 
    0xa, 0x2, 0x112, 0x114, 0x5, 0x4, 0x3, 0x2, 0x113, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0xc, 
    0x2, 0x2, 0x119, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x5, 0x12, 
    0xa, 0x2, 0x120, 0x124, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 0x5, 0x4, 
    0x3, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x127, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x127, 0x128, 0x7, 0x13, 0x2, 0x2, 0x128, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x129, 0x133, 0x7, 0x12, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0xc, 
    0x7, 0x2, 0x12b, 0x12c, 0x7, 0xc, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x131, 0x3, 0x2, 
    0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x132, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x134, 0x5, 0xc, 0x7, 0x2, 0x133, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x7, 0x13, 0x2, 0x2, 0x136, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x139, 0x5, 0x4, 0x3, 0x2, 0x138, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x14d, 0x7, 0xe, 
    0x2, 0x2, 0x13e, 0x142, 0x5, 0x1c, 0xf, 0x2, 0x13f, 0x141, 0x5, 0x4, 
    0x3, 0x2, 0x140, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x143, 0x145, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x146, 0x7, 0xc, 0x2, 0x2, 0x146, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14e, 0x5, 0x1c, 0xf, 0x2, 0x14d, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x151, 0x5, 0x4, 0x3, 0x2, 0x150, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x154, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x155, 0x1ac, 0x7, 0xf, 
    0x2, 0x2, 0x156, 0x158, 0x5, 0x4, 0x3, 0x2, 0x157, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15c, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x168, 0x7, 0xe, 
    0x2, 0x2, 0x15d, 0x161, 0x5, 0x1a, 0xe, 0x2, 0x15e, 0x160, 0x5, 0x4, 
    0x3, 0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x164, 0x3, 0x2, 0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x165, 0x7, 0xc, 0x2, 0x2, 0x165, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 
    0x2, 0x2, 0x16b, 0x16c, 0x5, 0x1a, 0xe, 0x2, 0x16c, 0x170, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16f, 0x5, 0x4, 0x3, 0x2, 0x16e, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x173, 0x3, 0x2, 
    0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0xf, 
    0x2, 0x2, 0x174, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x175, 0x177, 0x5, 0x4, 
    0x3, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x187, 0x7, 0xe, 0x2, 0x2, 0x17c, 0x180, 0x5, 0x1c, 
    0xf, 0x2, 0x17d, 0x17f, 0x5, 0x4, 0x3, 0x2, 0x17e, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x182, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0xc, 
    0x2, 0x2, 0x184, 0x186, 0x3, 0x2, 0x2, 0x2, 0x185, 0x17c, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x189, 0x3, 0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x1c, 
    0xf, 0x2, 0x18b, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 0x5, 0x4, 
    0x3, 0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x192, 0x3, 0x2, 0x2, 0x2, 0x191, 0x18f, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x19e, 0x7, 0xc, 0x2, 0x2, 0x193, 0x197, 0x5, 0x1a, 
    0xe, 0x2, 0x194, 0x196, 0x5, 0x4, 0x3, 0x2, 0x195, 0x194, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x199, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x19a, 0x3, 0x2, 
    0x2, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0xc, 
    0x2, 0x2, 0x19b, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 0x3, 0x2, 
    0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x1a, 
    0xe, 0x2, 0x1a2, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a5, 0x5, 0x4, 
    0x3, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a8, 0x3, 0x2, 
    0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1a7, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 
    0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0xf, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x159, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x178, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1af, 0x5, 0x4, 0x3, 0x2, 0x1ae, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1af, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b7, 0x7, 0x1f, 0x2, 
    0x2, 0x1b4, 0x1b6, 0x5, 0x4, 0x3, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x3, 0x2, 0x2, 
    0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x10, 0x2, 
    0x2, 0x1bb, 0x1bc, 0x5, 0x1c, 0xf, 0x2, 0x1bc, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1c1, 0x8, 0xf, 0x1, 0x2, 0x1be, 0x1c0, 0x5, 0x4, 0x3, 
    0x2, 0x1bf, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 
    0x2, 0x1c2, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x1c4, 0x1cd, 0x7, 0x1f, 0x2, 0x2, 0x1c5, 0x1c7, 0x5, 0x4, 0x3, 
    0x2, 0x1c6, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1ca, 0x3, 0x2, 0x2, 
    0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 
    0x2, 0x1c9, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 
    0x2, 0x1cb, 0x1cd, 0x5, 0x1e, 0x10, 0x2, 0x1cc, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1f3, 0x3, 0x2, 0x2, 
    0x2, 0x1ce, 0x1d2, 0xc, 0x5, 0x2, 0x2, 0x1cf, 0x1d1, 0x5, 0x4, 0x3, 
    0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x1d9, 0x7, 0x14, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x4, 0x3, 
    0x2, 0x1d7, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1db, 0x3, 0x2, 0x2, 
    0x2, 0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1dc, 0x1f2, 0x7, 0x1f, 0x2, 0x2, 0x1dd, 0x1df, 0xc, 0x4, 0x2, 
    0x2, 0x1de, 0x1e0, 0x5, 0x16, 0xc, 0x2, 0x1df, 0x1de, 0x3, 0x2, 0x2, 
    0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x1f2, 0x5, 0x18, 0xd, 0x2, 0x1e2, 0x1e6, 0xc, 0x3, 0x2, 
    0x2, 0x1e3, 0x1e5, 0x5, 0x4, 0x3, 0x2, 0x1e4, 0x1e3, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e9, 0x3, 0x2, 0x2, 
    0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ed, 0x7, 0x15, 0x2, 
    0x2, 0x1ea, 0x1ec, 0x5, 0x4, 0x3, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 
    0x2, 0x1ec, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 
    0x2, 0x1ed, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f2, 0x5, 0xc, 0x7, 
    0x2, 0x1f1, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1dd, 0x3, 0x2, 0x2, 
    0x2, 0x1f1, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1f6, 0x1fc, 0x5, 0x20, 0x11, 0x2, 0x1f7, 0x1fc, 0x7, 0x1b, 0x2, 0x2, 
    0x1f8, 0x1fc, 0x7, 0x1c, 0x2, 0x2, 0x1f9, 0x1fc, 0x7, 0x1d, 0x2, 0x2, 
    0x1fa, 0x1fc, 0x7, 0x1e, 0x2, 0x2, 0x1fb, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1f8, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fa, 0x3, 0x2, 0x2, 0x2, 
    0x1fc, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1ff, 0x7, 0x16, 0x2, 0x2, 
    0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 
    0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x7, 0x1a, 0x2, 0x2, 
    0x201, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x25, 0x2b, 0x31, 0x36, 0x3b, 
    0x43, 0x4b, 0x52, 0x59, 0x5e, 0x64, 0x6d, 0x72, 0x77, 0x7d, 0x82, 0x89, 
    0x8d, 0x93, 0x98, 0x9d, 0xa5, 0xac, 0xb0, 0xb5, 0xbc, 0xc4, 0xc9, 0xcf, 
    0xd6, 0xdc, 0xe3, 0xec, 0xf5, 0xfc, 0x103, 0x108, 0x10d, 0x115, 0x11c, 
    0x124, 0x12f, 0x133, 0x13a, 0x142, 0x149, 0x14d, 0x152, 0x159, 0x161, 
    0x168, 0x170, 0x178, 0x180, 0x187, 0x18f, 0x197, 0x19e, 0x1a6, 0x1ab, 
    0x1b0, 0x1b7, 0x1c1, 0x1c8, 0x1cc, 0x1d2, 0x1d9, 0x1df, 0x1e6, 0x1ed, 
    0x1f1, 0x1f3, 0x1fb, 0x1fe, 
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
