module.exports = grammar({
  name: "jule",

  extras: ($) => [
    $.comment,
    /\s+/,
  ],

  word: ($) => $.identifier,

  rules: {

    source_file: $ => repeat(choice($.comment)),

    identifier: (_) => /[a-zA-Zα-ωΑ-Ωµ_][a-zA-Zα-ωΑ-Ωµ\d_]*/,

    //------------Comments------------//
    comment: $ => choice(
      $.line_comment,
      $.block_comment
    ),

    line_comment: ($) => token(seq("//", /[^\r\n]*/)),
    block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')),
  },
});
