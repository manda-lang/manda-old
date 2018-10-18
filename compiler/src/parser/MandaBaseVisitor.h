
// Generated from /Users/thosakwe/Source/Compilers/manda/compiler/src/parser/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MandaVisitor.h"


namespace parser {

/**
 * This class provides an empty implementation of MandaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MandaBaseVisitor : public MandaVisitor {
public:

  virtual antlrcpp::Any visitCompilationUnit(MandaParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirective(MandaParser::DirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportDirective(MandaParser::ImportDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAliasDecl(MandaParser::TypeAliasDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDecl(MandaParser::FuncDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBody(MandaParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(MandaParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(MandaParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowBlock(MandaParser::ArrowBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyBlock(MandaParser::EmptyBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurlyBlock(MandaParser::CurlyBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionType(MandaParser::UnionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructType(MandaParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenType(MandaParser::ParenTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdType(MandaParser::IdTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructTypeConstructor(MandaParser::StructTypeConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructTypeGetter(MandaParser::StructTypeGetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructTypeSetter(MandaParser::StructTypeSetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructTypeField(MandaParser::StructTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprStmt(MandaParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclStmt(MandaParser::VarDeclStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(MandaParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTryStmt(MandaParser::TryStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(MandaParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerExpr(MandaParser::IntegerExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatExpr(MandaParser::FloatExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrueExpr(MandaParser::TrueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexExpr(MandaParser::HexExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddOrSubExpr(MandaParser::AddOrSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpr(MandaParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalseExpr(MandaParser::FalseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolAndOrExpr(MandaParser::BoolAndOrExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace parser
