
// Generated from /Users/thosakwe/Source/Compilers/manda/compiler/src/parser/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MandaParser.h"


namespace parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MandaParser.
 */
class  MandaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MandaParser.
   */
    virtual antlrcpp::Any visitCompilationUnit(MandaParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitDirective(MandaParser::DirectiveContext *context) = 0;

    virtual antlrcpp::Any visitImportDirective(MandaParser::ImportDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitTypeAliasDecl(MandaParser::TypeAliasDeclContext *context) = 0;

    virtual antlrcpp::Any visitFuncDecl(MandaParser::FuncDeclContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBody(MandaParser::FunctionBodyContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(MandaParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameter(MandaParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitArrowBlock(MandaParser::ArrowBlockContext *context) = 0;

    virtual antlrcpp::Any visitEmptyBlock(MandaParser::EmptyBlockContext *context) = 0;

    virtual antlrcpp::Any visitCurlyBlock(MandaParser::CurlyBlockContext *context) = 0;

    virtual antlrcpp::Any visitUnionType(MandaParser::UnionTypeContext *context) = 0;

    virtual antlrcpp::Any visitStructType(MandaParser::StructTypeContext *context) = 0;

    virtual antlrcpp::Any visitParenType(MandaParser::ParenTypeContext *context) = 0;

    virtual antlrcpp::Any visitIdType(MandaParser::IdTypeContext *context) = 0;

    virtual antlrcpp::Any visitStructTypeConstructor(MandaParser::StructTypeConstructorContext *context) = 0;

    virtual antlrcpp::Any visitStructTypeGetter(MandaParser::StructTypeGetterContext *context) = 0;

    virtual antlrcpp::Any visitStructTypeSetter(MandaParser::StructTypeSetterContext *context) = 0;

    virtual antlrcpp::Any visitStructTypeField(MandaParser::StructTypeFieldContext *context) = 0;

    virtual antlrcpp::Any visitExprStmt(MandaParser::ExprStmtContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclStmt(MandaParser::VarDeclStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(MandaParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(MandaParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitTryStmt(MandaParser::TryStmtContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(MandaParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitIntegerExpr(MandaParser::IntegerExprContext *context) = 0;

    virtual antlrcpp::Any visitFloatExpr(MandaParser::FloatExprContext *context) = 0;

    virtual antlrcpp::Any visitTrueExpr(MandaParser::TrueExprContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpr(MandaParser::IdentifierExprContext *context) = 0;

    virtual antlrcpp::Any visitHexExpr(MandaParser::HexExprContext *context) = 0;

    virtual antlrcpp::Any visitAddOrSubExpr(MandaParser::AddOrSubExprContext *context) = 0;

    virtual antlrcpp::Any visitParenExpr(MandaParser::ParenExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *context) = 0;

    virtual antlrcpp::Any visitFalseExpr(MandaParser::FalseExprContext *context) = 0;

    virtual antlrcpp::Any visitBoolAndOrExpr(MandaParser::BoolAndOrExprContext *context) = 0;


};

}  // namespace parser
