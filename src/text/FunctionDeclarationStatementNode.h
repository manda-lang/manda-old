// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_FUNCTIONDECLARATIONSTATEMENTNODE_H
#define MANDA_FUNCTIONDECLARATIONSTATEMENTNODE_H

#include "FunctionBodyNode.h"
#include "FunctionSignatureNode.h"
#include "SimpleIdentifierNode.h"
#include "StatementNode.h"

namespace manda
{

    class FunctionDeclarationStatementNode : public StatementNode
    {
    public:
        explicit FunctionDeclarationStatementNode(SimpleIdentifierNode *identifier,
                                                  FunctionSignatureNode *signature, FunctionBodyNode *body);

        ~FunctionDeclarationStatementNode();

        const SimpleIdentifierNode *GetIdentifier() const;

        const FunctionSignatureNode *GetSignature() const;

        const FunctionBodyNode *GetBody() const;

    public:
        const SourceSpan *GetSourceSpan() const override;

        bool HasFunctionDeclaration() const override;

        bool IsExpressionStatement() const override;

        void AcceptAnalyzer(Analyzer *analyzer) const override;

    private:
        SimpleIdentifierNode *identifier;
        FunctionSignatureNode *signature;
        FunctionBodyNode *body;
    };
}

#endif //MANDA_FUNCTIONDECLARATIONSTATEMENTNODE_H
