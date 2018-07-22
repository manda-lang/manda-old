
// Generated from /Users/thosakwe/Source/Compilers/manda/src/manda_text/Manda.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MandaParser.h"


namespace manda_text {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MandaParser.
 */
class  MandaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MandaParser.
   */
    virtual antlrcpp::Any visitProgram(MandaParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitDocComment(MandaParser::DocCommentContext *context) = 0;

    virtual antlrcpp::Any visitSingleLineComment(MandaParser::SingleLineCommentContext *context) = 0;

    virtual antlrcpp::Any visitImportDirective(MandaParser::ImportDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitWithDirective(MandaParser::WithDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitTypedefDirective(MandaParser::TypedefDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(MandaParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(MandaParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationStatement(MandaParser::VariableDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitLetModifier(MandaParser::LetModifierContext *context) = 0;

    virtual antlrcpp::Any visitVarModifier(MandaParser::VarModifierContext *context) = 0;

    virtual antlrcpp::Any visitUnionType(MandaParser::UnionTypeContext *context) = 0;

    virtual antlrcpp::Any visitStructType(MandaParser::StructTypeContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedType(MandaParser::ParenthesizedTypeContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierType(MandaParser::IdentifierTypeContext *context) = 0;

    virtual antlrcpp::Any visitStructTypeField(MandaParser::StructTypeFieldContext *context) = 0;

    virtual antlrcpp::Any visitTypeAnnotation(MandaParser::TypeAnnotationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierTypeParameter(MandaParser::IdentifierTypeParameterContext *context) = 0;

    virtual antlrcpp::Any visitExtendsTypeParameter(MandaParser::ExtendsTypeParameterContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameterList(MandaParser::TypeParameterListContext *context) = 0;

    virtual antlrcpp::Any visitTypeArgumentList(MandaParser::TypeArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitPositionalParameterList(MandaParser::PositionalParameterListContext *context) = 0;

    virtual antlrcpp::Any visitNamedParameterList(MandaParser::NamedParameterListContext *context) = 0;

    virtual antlrcpp::Any visitMixedParameterList(MandaParser::MixedParameterListContext *context) = 0;

    virtual antlrcpp::Any visitNamedArgument(MandaParser::NamedArgumentContext *context) = 0;

    virtual antlrcpp::Any visitMemberExpression(MandaParser::MemberExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpression(MandaParser::LiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdExpression(MandaParser::IdExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCallExpression(MandaParser::CallExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAsExpression(MandaParser::AsExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(MandaParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitDecimalLiteral(MandaParser::DecimalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBinaryLiteral(MandaParser::BinaryLiteralContext *context) = 0;

    virtual antlrcpp::Any visitHexLiteral(MandaParser::HexLiteralContext *context) = 0;

    virtual antlrcpp::Any visitOctalLiteral(MandaParser::OctalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitString(MandaParser::StringContext *context) = 0;


};

}  // namespace manda_text
