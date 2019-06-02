Project page:
   https://github.com/wormt/bcc

Overview of features:
   https://github.com/wormt/bcc/blob/bcs/doc/details.md

Version: 0.8.0
=============================================================================

Known issues in this release:
- File path of cached library file now shown in diagnostic messages.
- memcpy() breaks when both the source and destination operands are array
  references.
- memcpy() of global and world arrays may cause the game to crash.
