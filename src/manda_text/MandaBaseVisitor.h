
// Generated from /Users/thosakwe/Source/Compilers/manda/src/manda_text/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MandaVisitor.h"


namespace manda_text {

/**
 * This class provides an empty implementation of MandaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MandaBaseVisitor : public MandaVisitor {
public:

  virtual antlrcpp::Any visitProgram(MandaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDocComment(MandaParser::DocCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleLineComment(MandaParser::SingleLineCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportDirective(MandaParser::ImportDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWithDirective(MandaParser::WithDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedefDirective(MandaParser::TypedefDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(MandaParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(MandaParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationStatement(MandaParser::VariableDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLetModifier(MandaParser::LetModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarModifier(MandaParser::VarModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionType(MandaParser::UnionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructType(MandaParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedType(MandaParser::ParenthesizedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierType(MandaParser::IdentifierTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructTypeField(MandaParser::StructTypeFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAnnotation(MandaParser::TypeAnnotationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierTypeParameter(MandaParser::IdentifierTypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtendsTypeParameter(MandaParser::ExtendsTypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeParameterList(MandaParser::TypeParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeArgumentList(MandaParser::TypeArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositionalParameterList(MandaParser::PositionalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedParameterList(MandaParser::NamedParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMixedParameterList(MandaParser::MixedParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedArgument(MandaParser::NamedArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberExpression(MandaParser::MemberExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(MandaParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExpression(MandaParser::IdExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExpression(MandaParser::CallExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsExpression(MandaParser::AsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteral(MandaParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecimalLiteral(MandaParser::DecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryLiteral(MandaParser::BinaryLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexLiteral(MandaParser::HexLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOctalLiteral(MandaParser::OctalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(MandaParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace manda_text
