# Contribution Guidelines
Firstly, thanks for the contribution to Manda! It's greatly appreciated; your work goes
a long way.

In order to maintain the quality of Manda and its ecosystem, the process required to land a
change is relatively involved, and filters out unnecessary additions.

**Make sure you read this document very carefully. If not, your issue/pull request may be
rejected, without any warning.**

## BDFL
As with several other open-source projects, Manda's operation is overseen by its
"benevolent dictator for life," Tobe Osakwe (@thosakwe).

He will weigh the merits of every change, and ultimately have the final say. The goal of this
to ensure both a clear vision for the future of Manda, and to only make decisions that are for
the better.

## Filing an Issue
Issues filed **must** fall into one (or more) of the following categories:
* Bug Report
* Documentation Issue
* Feature Request

### Filing a Bug Report
Include:
* The version of Manda
* Your operating system + version
* A description of the expected behavior
* A description of the behavior that *actually* occurs
* Steps to reproduce the bug

**Without reproduction instructions, your issue will be closed. You may request it to be
re-opened after adding the necessary guidelines.**

### Documentation Issue
* Describe what you think is wrong with the documentation
* Give an example of content you think would be better at explaining the concept in
question

Documentation issues are typically the easiest time you will have with the Manda issue tracker.
**Make sure to include example content, otherwise your issue will be closed.**

### Feature Request
Right off the bat, let this be known - **the majority of feature requests will be rejected.**

Feature creep is a real thing. Every new feature added to a language requires many unit tests to
ensure it works properly in all implementations of the language, in addition to modifications to
the parser, static analyzer, and JIT compiler.

Simply put - more features means more potential bugs, and not every feature is worth the pain.

If submitting a feature request, provide:
* A succinct (<80 characters) description of the feature
* Is this an addition/change to the language's syntax? Good luck.
* The current pattern used to achieve the desired functionality in Manda (if possible)
* The desired pattern, which you are proposing be added to Manda
* At least 3 compelling reasons why this feature *must* be added to Manda.
* At least 3 compelling reasons why *not* having this feature will make people/companies
choose to avoid Manda.
* 3 potential negative consequences to adding this feature to Manda.

#### Pitching a Syntax Change
In **addition** to the above information, if you are proposing a syntax change, you **must**
explain why this feature is so important, that the entire syntax of the language should be
changed to include it. As you can imagine, a syntax change is a much more breaking change than
a mere library addition/modification.

Notes:
* "Other languages have it" is **not** a compelling reason. Avoid this.
* "Other languages have it" is **not** a compelling reason. Avoid this.
* "Other languages have it" is **not** a compelling reason. Avoid this.

## Sending a Pull Request
You **must** file an issue BEFORE sending in a pull request. There are no exceptions to this rule.
The related issue **must** be linked within the pull request. If you do not comply to the
aforementioned rules, your pull request will be immediately rejected.

In addition, Manda's operation is ensured using the [Travis](https://travis-ci.org/)
continuous integration system.
If you are making any change to Manda's functionality, you **must** include sufficient
unit tests. These tests must pass in Travis; if they don't, the pull request will be closed.
If the tests are fixed and eventually pass, you may request a reopening of the pull request.