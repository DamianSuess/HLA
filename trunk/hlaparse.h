/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     dupTkn = 258,
     lorTkn = 259,
     orTkn = 260,
     landTkn = 261,
     andTkn = 262,
     inTkn = 263,
     neTkn = 264,
     geTkn = 265,
     leTkn = 266,
     shropTkn = 267,
     shlopTkn = 268,
     modTkn = 269,
     divTkn = 270,
     notTkn = 271,
     UMINUS = 272,
     intconst = 273,
     hexconst = 274,
     binconst = 275,
     fltconst = 276,
     charconst = 277,
     wcharconst = 278,
     strconst = 279,
     wstrconst = 280,
     regexconst = 281,
     assignTkn = 282,
     addassignTkn = 283,
     subassignTkn = 284,
     DotDot = 285,
     coloncolonTkn = 286,
     matchTkn = 287,
     match2Tkn = 288,
     stmtsTkn = 289,
     endstmtsTkn = 290,
     UndefID = 291,
     RegexID = 292,
     atTkn = 293,
     posTkn = 294,
     tabTkn = 295,
     arbTkn = 296,
     LocalID = 297,
     LocalConstID = 298,
     LocalVarID = 299,
     LocalStaticID = 300,
     LocalProcID = 301,
     LocalIterID = 302,
     LocalMethodID = 303,
     LocalLabelID = 304,
     NonLocalID = 305,
     NonLocalConstID = 306,
     NonLocalVarID = 307,
     NonLocalStaticID = 308,
     NonLocalProcID = 309,
     NonLocalIterID = 310,
     NonLocalMethodID = 311,
     NonLocalLabelID = 312,
     OverloadedID = 313,
     ovldClassTkn = 314,
     ClassVarID = 315,
     ClassStaticID = 316,
     ClassProcID = 317,
     ClassIterID = 318,
     ClassMethodID = 319,
     MacroParmTkn = 320,
     LastMacroParmTkn = 321,
     MacroID = 322,
     DoMacroDclTkn = 323,
     DoRegexDclTkn = 324,
     compileRegexTkn = 325,
     TextParameters = 326,
     DoOneValStmt = 327,
     DoOneConstExpr = 328,
     ctforTkn = 329,
     textblockTkn = 330,
     endtextTkn = 331,
     stringblockTkn = 332,
     endstringTkn = 333,
     matchblockTkn = 334,
     endmatchTkn = 335,
     beginTkn = 336,
     endTkn = 337,
     procTkn = 338,
     endprocTkn = 339,
     procedureTkn = 340,
     iteratorTkn = 341,
     methodTkn = 342,
     programTkn = 343,
     unitTkn = 344,
     macroTkn = 345,
     keywordTkn = 346,
     terminatorTkn = 347,
     endmacroTkn = 348,
     endMacDefTkn = 349,
     regexMacroTkn = 350,
     endregexTkn = 351,
     endRegexDefTkn = 352,
     regexReturnTkn = 353,
     labelTkn = 354,
     endlabelTkn = 355,
     constTkn = 356,
     endconstTkn = 357,
     valTkn = 358,
     endvalTkn = 359,
     typeTkn = 360,
     endtypeTkn = 361,
     alignTkn = 362,
     varTkn = 363,
     endvarTkn = 364,
     staticTkn = 365,
     endstaticTkn = 366,
     uninitializedTkn = 367,
     endstorageTkn = 368,
     readonlyTkn = 369,
     endreadonlyTkn = 370,
     recordTkn = 371,
     endrecordTkn = 372,
     unionTkn = 373,
     endunionTkn = 374,
     classTkn = 375,
     vmtTkn = 376,
     endclassTkn = 377,
     enumTkn = 378,
     inheritsTkn = 379,
     pointerTkn = 380,
     toTkn = 381,
     downtoTkn = 382,
     externalTkn = 383,
     abstractTkn = 384,
     overloadsTkn = 385,
     overrideTkn = 386,
     overridesTkn = 387,
     forwardTkn = 388,
     returnsTkn = 389,
     atreturnsTkn = 390,
     noframeTkn = 391,
     frameTkn = 392,
     nodisplayTkn = 393,
     displayTkn = 394,
     noalignstkTkn = 395,
     alignstkTkn = 396,
     alignprocTkn = 397,
     useTkn = 398,
     useenterTkn = 399,
     noenterTkn = 400,
     useleaveTkn = 401,
     noleaveTkn = 402,
     pascalTkn = 403,
     cdeclTkn = 404,
     stdcallTkn = 405,
     nostorageTkn = 406,
     volatileTkn = 407,
     namespaceTkn = 408,
     fastTkn = 409,
     segmentTkn = 410,
     hereTkn = 411,
     atlabelTkn = 412,
     nameTkn = 413,
     valresTkn = 414,
     resultTkn = 415,
     lazyTkn = 416,
     thunkTkn = 417,
     jtTkn = 418,
     jfTkn = 419,
     ifTkn = 420,
     thenTkn = 421,
     elseifTkn = 422,
     elseTkn = 423,
     endifTkn = 424,
     switchTkn = 425,
     caseTkn = 426,
     defaultTkn = 427,
     endswitchTkn = 428,
     whileTkn = 429,
     doTkn = 430,
     endwhileTkn = 431,
     welseTkn = 432,
     repeatTkn = 433,
     untilTkn = 434,
     forTkn = 435,
     foreverTkn = 436,
     foreachTkn = 437,
     endforTkn = 438,
     felseTkn = 439,
     exitTkn = 440,
     exitifTkn = 441,
     breakTkn = 442,
     breakifTkn = 443,
     continueTkn = 444,
     continueifTkn = 445,
     tryTkn = 446,
     alwaysTkn = 447,
     unprotectedTkn = 448,
     exceptionTkn = 449,
     anyexceptionTkn = 450,
     endtryTkn = 451,
     raiseTkn = 452,
     booleanTkn = 453,
     int8Tkn = 454,
     int16Tkn = 455,
     int32Tkn = 456,
     int64Tkn = 457,
     int128Tkn = 458,
     charTkn = 459,
     wcharTkn = 460,
     real32Tkn = 461,
     real64Tkn = 462,
     real80Tkn = 463,
     real128Tkn = 464,
     uns8Tkn = 465,
     uns16Tkn = 466,
     uns32Tkn = 467,
     uns64Tkn = 468,
     uns128Tkn = 469,
     stringTkn = 470,
     wstringTkn = 471,
     zstringTkn = 472,
     csetTkn = 473,
     regexTkn = 474,
     textTkn = 475,
     byteTkn = 476,
     wordTkn = 477,
     dwordTkn = 478,
     qwordTkn = 479,
     tbyteTkn = 480,
     lwordTkn = 481,
     atint8Tkn = 482,
     atint16Tkn = 483,
     atint32Tkn = 484,
     atint64Tkn = 485,
     atint128Tkn = 486,
     atcharTkn = 487,
     atwcharTkn = 488,
     atreal32Tkn = 489,
     atreal64Tkn = 490,
     atreal80Tkn = 491,
     atuns8Tkn = 492,
     atuns16Tkn = 493,
     atuns32Tkn = 494,
     atuns64Tkn = 495,
     atuns128Tkn = 496,
     atstringTkn = 497,
     atwstringTkn = 498,
     atcsetTkn = 499,
     atbyteTkn = 500,
     atwordTkn = 501,
     atdwordTkn = 502,
     atqwordTkn = 503,
     attbyteTkn = 504,
     atlwordTkn = 505,
     atpointerTkn = 506,
     nullTkn = 507,
     absTkn = 508,
     ceilTkn = 509,
     cosTkn = 510,
     dateTkn = 511,
     envTkn = 512,
     expTkn = 513,
     extractTkn = 514,
     floorTkn = 515,
     isalphaTkn = 516,
     isalphanumTkn = 517,
     isdigitTkn = 518,
     islowerTkn = 519,
     isspaceTkn = 520,
     isupperTkn = 521,
     isxdigitTkn = 522,
     logTkn = 523,
     log10Tkn = 524,
     maxTkn = 525,
     minTkn = 526,
     oddTkn = 527,
     randomTkn = 528,
     randomizeTkn = 529,
     readTkn = 530,
     sinTkn = 531,
     sortTkn = 532,
     sqrtTkn = 533,
     systemTkn = 534,
     tanTkn = 535,
     threadTkn = 536,
     timeTkn = 537,
     peekcsetTkn = 538,
     onecsetTkn = 539,
     uptocsetTkn = 540,
     zerooronecsetTkn = 541,
     zeroormorecsetTkn = 542,
     oneormorecsetTkn = 543,
     exactlyncsetTkn = 544,
     firstncsetTkn = 545,
     norlesscsetTkn = 546,
     normorecsetTkn = 547,
     ntomcsetTkn = 548,
     exactlyntomcsetTkn = 549,
     peekcharTkn = 550,
     onecharTkn = 551,
     uptocharTkn = 552,
     zerooronecharTkn = 553,
     zeroormorecharTkn = 554,
     oneormorecharTkn = 555,
     exactlyncharTkn = 556,
     firstncharTkn = 557,
     norlesscharTkn = 558,
     normorecharTkn = 559,
     ntomcharTkn = 560,
     exactlyntomcharTkn = 561,
     peekicharTkn = 562,
     oneicharTkn = 563,
     uptoicharTkn = 564,
     zerooroneicharTkn = 565,
     zeroormoreicharTkn = 566,
     oneormoreicharTkn = 567,
     exactlynicharTkn = 568,
     firstnicharTkn = 569,
     norlessicharTkn = 570,
     normoreicharTkn = 571,
     ntomicharTkn = 572,
     exactlyntomicharTkn = 573,
     matchstrTkn = 574,
     matchistrTkn = 575,
     uptostrTkn = 576,
     uptoistrTkn = 577,
     matchtostrTkn = 578,
     matchtoistrTkn = 579,
     zeroormorewsTkn = 580,
     oneormorewsTkn = 581,
     wsoreosTkn = 582,
     wstheneosTkn = 583,
     peekwsTkn = 584,
     eosTkn = 585,
     wsTkn = 586,
     peekstrTkn = 587,
     peekistrTkn = 588,
     matchidTkn = 589,
     matchwordTkn = 590,
     matchiwordTkn = 591,
     matchintconstTkn = 592,
     matchrealconstTkn = 593,
     matchnumericconstTkn = 594,
     matchstrconstTkn = 595,
     matchregTkn = 596,
     matchreg8Tkn = 597,
     matchreg16Tkn = 598,
     matchreg32Tkn = 599,
     matchfpuregTkn = 600,
     matchmmxregTkn = 601,
     matchxmmregTkn = 602,
     deleteTkn = 603,
     indexTkn = 604,
     insertTkn = 605,
     lengthTkn = 606,
     lowercaseTkn = 607,
     replaceTkn = 608,
     rindexTkn = 609,
     strbrkTkn = 610,
     strsetTkn = 611,
     strspanTkn = 612,
     substrTkn = 613,
     tokenizeTkn = 614,
     trimTkn = 615,
     uppercaseTkn = 616,
     symNameTkn = 617,
     symTypeTkn = 618,
     sympTypeTkn = 619,
     symBasepTypeTkn = 620,
     symClassTkn = 621,
     symSizeTkn = 622,
     symOffsetTkn = 623,
     symLocalsymsTkn = 624,
     symParmsTkn = 625,
     symLexTkn = 626,
     symArityTkn = 627,
     symDimTkn = 628,
     symNumelementsTkn = 629,
     symDefinedTkn = 630,
     symTypeNameTkn = 631,
     symBaseTypeNameTkn = 632,
     sympClassTkn = 633,
     symStaticNameTkn = 634,
     symIsExternalTkn = 635,
     symIsConstTkn = 636,
     symIsClassTkn = 637,
     symElementSizeTkn = 638,
     symIsRegTkn = 639,
     symIsReg8Tkn = 640,
     symIsReg16Tkn = 641,
     symIsReg32Tkn = 642,
     symIsfRegTkn = 643,
     symIsMemTkn = 644,
     symIsTypeTkn = 645,
     curLexTkn = 646,
     curOffsetTkn = 647,
     curDirTkn = 648,
     addOffset1stTkn = 649,
     lineNumberTkn = 650,
     lineNumberStkTkn = 651,
     errorPrefixTkn = 652,
     filenameTkn = 653,
     fileNameStkTkn = 654,
     startParmOfsTkn = 655,
     startLclOfsTkn = 656,
     enumSizeTkn = 657,
     lastMacroObjectTkn = 658,
     curObjectNameTkn = 659,
     sectionTkn = 660,
     boundvarTkn = 661,
     intovarTkn = 662,
     traceTkn = 663,
     exceptsTkn = 664,
     optstringsTkn = 665,
     baseregTkn = 666,
     st0Tkn = 667,
     st1Tkn = 668,
     st2Tkn = 669,
     st3Tkn = 670,
     st4Tkn = 671,
     st5Tkn = 672,
     st6Tkn = 673,
     st7Tkn = 674,
     alTkn = 675,
     ahTkn = 676,
     axTkn = 677,
     eaxTkn = 678,
     blTkn = 679,
     bhTkn = 680,
     bxTkn = 681,
     ebxTkn = 682,
     clTkn = 683,
     chTkn = 684,
     cxTkn = 685,
     ecxTkn = 686,
     dlTkn = 687,
     dhTkn = 688,
     dxTkn = 689,
     edxTkn = 690,
     siTkn = 691,
     esiTkn = 692,
     diTkn = 693,
     ediTkn = 694,
     bpTkn = 695,
     ebpTkn = 696,
     spTkn = 697,
     espTkn = 698,
     mm0Tkn = 699,
     mm1Tkn = 700,
     mm2Tkn = 701,
     mm3Tkn = 702,
     mm4Tkn = 703,
     mm5Tkn = 704,
     mm6Tkn = 705,
     mm7Tkn = 706,
     xmm0Tkn = 707,
     xmm1Tkn = 708,
     xmm2Tkn = 709,
     xmm3Tkn = 710,
     xmm4Tkn = 711,
     xmm5Tkn = 712,
     xmm6Tkn = 713,
     xmm7Tkn = 714,
     csTkn = 715,
     dsTkn = 716,
     esTkn = 717,
     fsTkn = 718,
     gsTkn = 719,
     ssTkn = 720,
     cr0Tkn = 721,
     cr1Tkn = 722,
     cr2Tkn = 723,
     cr3Tkn = 724,
     cr4Tkn = 725,
     cr5Tkn = 726,
     cr6Tkn = 727,
     cr7Tkn = 728,
     dr0Tkn = 729,
     dr1Tkn = 730,
     dr2Tkn = 731,
     dr3Tkn = 732,
     dr4Tkn = 733,
     dr5Tkn = 734,
     dr6Tkn = 735,
     dr7Tkn = 736,
     dxaxTkn = 737,
     edxeaxTkn = 738,
     cTkn = 739,
     ncTkn = 740,
     oTkn = 741,
     noTkn = 742,
     sTkn = 743,
     nsTkn = 744,
     zTkn = 745,
     nzTkn = 746,
     aTkn = 747,
     naTkn = 748,
     aeTkn = 749,
     naeTkn = 750,
     bTkn = 751,
     nbTkn = 752,
     beTkn = 753,
     nbeTkn = 754,
     eTkn = 755,
     gTkn = 756,
     ngTkn = 757,
     ngeTkn = 758,
     lTkn = 759,
     nlTkn = 760,
     nleTkn = 761,
     peTkn = 762,
     poTkn = 763,
     npTkn = 764,
     pTkn = 765,
     aaaTkn = 766,
     aadTkn = 767,
     aamTkn = 768,
     aasTkn = 769,
     adcTkn = 770,
     lockadcTkn = 771,
     addTkn = 772,
     lockaddTkn = 773,
     lockandTkn = 774,
     arplTkn = 775,
     boundTkn = 776,
     bsfTkn = 777,
     bsrTkn = 778,
     bswapTkn = 779,
     btTkn = 780,
     btcTkn = 781,
     lockbtcTkn = 782,
     btrTkn = 783,
     lockbtrTkn = 784,
     btsTkn = 785,
     lockbtsTkn = 786,
     callTkn = 787,
     cbwTkn = 788,
     cdqTkn = 789,
     clcTkn = 790,
     cldTkn = 791,
     cliTkn = 792,
     cltsTkn = 793,
     cmcTkn = 794,
     cmovoTkn = 795,
     cmovnoTkn = 796,
     cmovbTkn = 797,
     cmovnbTkn = 798,
     cmoveTkn = 799,
     cmovneTkn = 800,
     cmovbeTkn = 801,
     cmovnbeTkn = 802,
     cmovsTkn = 803,
     cmovnsTkn = 804,
     cmovpTkn = 805,
     cmovnpTkn = 806,
     cmovlTkn = 807,
     cmovnlTkn = 808,
     cmovleTkn = 809,
     cmovnleTkn = 810,
     cmpTkn = 811,
     cmpsbTkn = 812,
     cmpsdTkn = 813,
     cmpswTkn = 814,
     cmpxchgTkn = 815,
     lockcmpxchgTkn = 816,
     cmpxchg8bTkn = 817,
     cpuidTkn = 818,
     cwdTkn = 819,
     cwdeTkn = 820,
     daaTkn = 821,
     dasTkn = 822,
     decTkn = 823,
     lockdecTkn = 824,
     enterTkn = 825,
     hltTkn = 826,
     idivTkn = 827,
     imodTkn = 828,
     imulTkn = 829,
     intmulTkn = 830,
     incTkn = 831,
     lockincTkn = 832,
     insbTkn = 833,
     insdTkn = 834,
     inswTkn = 835,
     intTkn = 836,
     intoTkn = 837,
     invdTkn = 838,
     invlpgTkn = 839,
     iretTkn = 840,
     iretdTkn = 841,
     jaTkn = 842,
     jaeTkn = 843,
     jbTkn = 844,
     jbeTkn = 845,
     jcTkn = 846,
     jeTkn = 847,
     jgTkn = 848,
     jgeTkn = 849,
     jlTkn = 850,
     jleTkn = 851,
     jnaTkn = 852,
     jnaeTkn = 853,
     jnbTkn = 854,
     jnbeTkn = 855,
     jncTkn = 856,
     jneTkn = 857,
     jngTkn = 858,
     jngeTkn = 859,
     jnlTkn = 860,
     jnleTkn = 861,
     jnoTkn = 862,
     joTkn = 863,
     jnpTkn = 864,
     jnsTkn = 865,
     jnzTkn = 866,
     jpTkn = 867,
     jpeTkn = 868,
     jpoTkn = 869,
     jsTkn = 870,
     jzTkn = 871,
     jcxzTkn = 872,
     jecxzTkn = 873,
     jmpTkn = 874,
     lahfTkn = 875,
     larTkn = 876,
     leaTkn = 877,
     ldsTkn = 878,
     lesTkn = 879,
     lfsTkn = 880,
     lgsTkn = 881,
     lssTkn = 882,
     lslTkn = 883,
     lgdtTkn = 884,
     lidtTkn = 885,
     lldtTkn = 886,
     sgdtTkn = 887,
     sidtTkn = 888,
     sldtTkn = 889,
     leaveTkn = 890,
     lodsbTkn = 891,
     lodsdTkn = 892,
     lodswTkn = 893,
     loopTkn = 894,
     loopeTkn = 895,
     loopzTkn = 896,
     loopneTkn = 897,
     loopnzTkn = 898,
     lmswTkn = 899,
     ltrTkn = 900,
     strTkn = 901,
     movTkn = 902,
     movsbTkn = 903,
     movsdTkn = 904,
     movswTkn = 905,
     movsxTkn = 906,
     movzxTkn = 907,
     mulTkn = 908,
     negTkn = 909,
     locknegTkn = 910,
     nopTkn = 911,
     locknotTkn = 912,
     lockorTkn = 913,
     outTkn = 914,
     outsbTkn = 915,
     outsdTkn = 916,
     outswTkn = 917,
     popTkn = 918,
     popaTkn = 919,
     popadTkn = 920,
     popfTkn = 921,
     popfdTkn = 922,
     pushTkn = 923,
     pushaTkn = 924,
     pushadTkn = 925,
     pushdTkn = 926,
     pushfTkn = 927,
     pushfdTkn = 928,
     pushwTkn = 929,
     rclTkn = 930,
     rcrTkn = 931,
     rdmsrTkn = 932,
     rdpmcTkn = 933,
     rdtscTkn = 934,
     rsmTkn = 935,
     repmovsbTkn = 936,
     repmovswTkn = 937,
     repmovsdTkn = 938,
     repinsbTkn = 939,
     repinswTkn = 940,
     repinsdTkn = 941,
     repoutsbTkn = 942,
     repoutswTkn = 943,
     repoutsdTkn = 944,
     repstosbTkn = 945,
     repstoswTkn = 946,
     repstosdTkn = 947,
     repecmpsbTkn = 948,
     repecmpswTkn = 949,
     repecmpsdTkn = 950,
     repzcmpsbTkn = 951,
     repzcmpswTkn = 952,
     repzcmpsdTkn = 953,
     repnecmpsbTkn = 954,
     repnecmpswTkn = 955,
     repnecmpsdTkn = 956,
     repnzcmpsbTkn = 957,
     repnzcmpswTkn = 958,
     repnzcmpsdTkn = 959,
     repescasbTkn = 960,
     repescaswTkn = 961,
     repescasdTkn = 962,
     repnescasbTkn = 963,
     repnescaswTkn = 964,
     repnescasdTkn = 965,
     repzscasbTkn = 966,
     repzscaswTkn = 967,
     repzscasdTkn = 968,
     repnzscasbTkn = 969,
     repnzscaswTkn = 970,
     repnzscasdTkn = 971,
     retTkn = 972,
     rolTkn = 973,
     rorTkn = 974,
     sahfTkn = 975,
     salTkn = 976,
     sarTkn = 977,
     sbbTkn = 978,
     locksbbTkn = 979,
     scasbTkn = 980,
     scasdTkn = 981,
     scaswTkn = 982,
     setbTkn = 983,
     setnbTkn = 984,
     setzTkn = 985,
     setnzTkn = 986,
     setbeTkn = 987,
     setnbeTkn = 988,
     setoTkn = 989,
     setnoTkn = 990,
     setsTkn = 991,
     setnsTkn = 992,
     setpTkn = 993,
     setnpTkn = 994,
     setlTkn = 995,
     setleTkn = 996,
     setnlTkn = 997,
     setnleTkn = 998,
     shlTkn = 999,
     shldTkn = 1000,
     shrTkn = 1001,
     shrdTkn = 1002,
     smswTkn = 1003,
     stcTkn = 1004,
     stdTkn = 1005,
     stiTkn = 1006,
     stosbTkn = 1007,
     stosdTkn = 1008,
     stoswTkn = 1009,
     subTkn = 1010,
     sysenterTkn = 1011,
     sysexitTkn = 1012,
     locksubTkn = 1013,
     testTkn = 1014,
     ud2Tkn = 1015,
     verrTkn = 1016,
     verwTkn = 1017,
     waitTkn = 1018,
     wbinvdTkn = 1019,
     wrmsrTkn = 1020,
     xaddTkn = 1021,
     lockxaddTkn = 1022,
     xchgTkn = 1023,
     lockxchgTkn = 1024,
     xlatTkn = 1025,
     xorTkn = 1026,
     lockxorTkn = 1027,
     fldTkn = 1028,
     fildTkn = 1029,
     fbldTkn = 1030,
     fstTkn = 1031,
     fstpTkn = 1032,
     fistTkn = 1033,
     fistpTkn = 1034,
     fisttpTkn = 1035,
     fbstpTkn = 1036,
     fxchTkn = 1037,
     fxamTkn = 1038,
     faddTkn = 1039,
     faddpTkn = 1040,
     fiaddTkn = 1041,
     fmulTkn = 1042,
     fmulpTkn = 1043,
     fimulTkn = 1044,
     fsubTkn = 1045,
     fsubpTkn = 1046,
     fsubrTkn = 1047,
     fsubrpTkn = 1048,
     fisubTkn = 1049,
     fisubrTkn = 1050,
     fdivTkn = 1051,
     fdivpTkn = 1052,
     fdivrTkn = 1053,
     fdivrpTkn = 1054,
     fidivTkn = 1055,
     fidivrTkn = 1056,
     fcomTkn = 1057,
     fcompTkn = 1058,
     fcomppTkn = 1059,
     ficomTkn = 1060,
     ficompTkn = 1061,
     fucomTkn = 1062,
     fucompTkn = 1063,
     fucomppTkn = 1064,
     fsqrtTkn = 1065,
     fabsTkn = 1066,
     fchsTkn = 1067,
     ftstTkn = 1068,
     fscaleTkn = 1069,
     fpremTkn = 1070,
     fprem1Tkn = 1071,
     frndintTkn = 1072,
     fxtractTkn = 1073,
     fldzTkn = 1074,
     fld1Tkn = 1075,
     fldpiTkn = 1076,
     fldl2tTkn = 1077,
     fldl2eTkn = 1078,
     fldlg2Tkn = 1079,
     fldln2Tkn = 1080,
     f2xm1Tkn = 1081,
     fsinTkn = 1082,
     fcosTkn = 1083,
     fsincosTkn = 1084,
     fptanTkn = 1085,
     fpatanTkn = 1086,
     fyl2xTkn = 1087,
     fyl2xp1Tkn = 1088,
     finitTkn = 1089,
     fninitTkn = 1090,
     fwaitTkn = 1091,
     fldcwTkn = 1092,
     fstcwTkn = 1093,
     fnstcwTkn = 1094,
     fclexTkn = 1095,
     fnclexTkn = 1096,
     fldenvTkn = 1097,
     fstenvTkn = 1098,
     fnstenvTkn = 1099,
     fsaveTkn = 1100,
     fnsaveTkn = 1101,
     frstorTkn = 1102,
     fstswTkn = 1103,
     fnstswTkn = 1104,
     fincstpTkn = 1105,
     fdecstpTkn = 1106,
     fnopTkn = 1107,
     ffreeTkn = 1108,
     fcmovaTkn = 1109,
     fcmovaeTkn = 1110,
     fcmovbTkn = 1111,
     fcmovbeTkn = 1112,
     fcmoveTkn = 1113,
     fcmovnaTkn = 1114,
     fcmovnaeTkn = 1115,
     fcmovnbTkn = 1116,
     fcmovnbeTkn = 1117,
     fcmovneTkn = 1118,
     fcmovnuTkn = 1119,
     fcmovuTkn = 1120,
     fcomiTkn = 1121,
     fcomipTkn = 1122,
     fucomiTkn = 1123,
     fucomipTkn = 1124,
     paddbTkn = 1125,
     paddwTkn = 1126,
     padddTkn = 1127,
     paddqTkn = 1128,
     paddsbTkn = 1129,
     paddswTkn = 1130,
     paddusbTkn = 1131,
     padduswTkn = 1132,
     psubbTkn = 1133,
     psubwTkn = 1134,
     psubdTkn = 1135,
     psubqTkn = 1136,
     psubsbTkn = 1137,
     psubswTkn = 1138,
     psubusbTkn = 1139,
     psubuswTkn = 1140,
     pmullwTkn = 1141,
     pmulhwTkn = 1142,
     pmulhuwTkn = 1143,
     pmuludqTkn = 1144,
     pmaddwdTkn = 1145,
     pmaxswTkn = 1146,
     pmaxubTkn = 1147,
     pminswTkn = 1148,
     pminubTkn = 1149,
     psadbwTkn = 1150,
     pextrwTkn = 1151,
     pinsrwTkn = 1152,
     pmovmskbTkn = 1153,
     pshufwTkn = 1154,
     pshufdTkn = 1155,
     pavgbTkn = 1156,
     pavgwTkn = 1157,
     pcmpeqbTkn = 1158,
     pcmpeqwTkn = 1159,
     pcmpeqdTkn = 1160,
     pcmpgtbTkn = 1161,
     pcmpgtwTkn = 1162,
     pcmpgtdTkn = 1163,
     packsswbTkn = 1164,
     packuswbTkn = 1165,
     packssdwTkn = 1166,
     punpcklbwTkn = 1167,
     punpcklwdTkn = 1168,
     punpckldqTkn = 1169,
     punpcklqdqTkn = 1170,
     punpckhbwTkn = 1171,
     punpckhwdTkn = 1172,
     punpckhdqTkn = 1173,
     punpckhqdqTkn = 1174,
     pandTkn = 1175,
     pandnTkn = 1176,
     porTkn = 1177,
     pxorTkn = 1178,
     psllwTkn = 1179,
     pslldTkn = 1180,
     psllqTkn = 1181,
     psrlwTkn = 1182,
     psrldTkn = 1183,
     psrlqTkn = 1184,
     psrawTkn = 1185,
     psradTkn = 1186,
     movdTkn = 1187,
     movqTkn = 1188,
     emmsTkn = 1189,
     addpdTkn = 1190,
     addsdTkn = 1191,
     addpsTkn = 1192,
     addssTkn = 1193,
     addsubpsTkn = 1194,
     addsubpdTkn = 1195,
     andnpdTkn = 1196,
     andnpsTkn = 1197,
     andpdTkn = 1198,
     andpsTkn = 1199,
     clflushTkn = 1200,
     cmppdTkn = 1201,
     cmppsTkn = 1202,
     cmpssTkn = 1203,
     cmpeqssTkn = 1204,
     cmplessTkn = 1205,
     cmpltssTkn = 1206,
     cmpneqssTkn = 1207,
     cmpnltssTkn = 1208,
     cmpnlessTkn = 1209,
     cmpordssTkn = 1210,
     cmpunordssTkn = 1211,
     cmpeqsdTkn = 1212,
     cmplesdTkn = 1213,
     cmpltsdTkn = 1214,
     cmpneqsdTkn = 1215,
     cmpnltsdTkn = 1216,
     cmpnlesdTkn = 1217,
     cmpordsdTkn = 1218,
     cmpunordsdTkn = 1219,
     cmpeqpsTkn = 1220,
     cmplepsTkn = 1221,
     cmpltpsTkn = 1222,
     cmpneqpsTkn = 1223,
     cmpnltpsTkn = 1224,
     cmpnlepsTkn = 1225,
     cmpordpsTkn = 1226,
     cmpunordpsTkn = 1227,
     cmpeqpdTkn = 1228,
     cmplepdTkn = 1229,
     cmpltpdTkn = 1230,
     cmpneqpdTkn = 1231,
     cmpnltpdTkn = 1232,
     cmpnlepdTkn = 1233,
     cmpordpdTkn = 1234,
     cmpunordpdTkn = 1235,
     comisdTkn = 1236,
     comissTkn = 1237,
     cvtdq2pdTkn = 1238,
     cvtdq2psTkn = 1239,
     cvtpd2dqTkn = 1240,
     cvtpd2piTkn = 1241,
     cvtpd2psTkn = 1242,
     cvtpi2pdTkn = 1243,
     cvtpi2psTkn = 1244,
     cvtps2dqTkn = 1245,
     cvtps2pdTkn = 1246,
     cvtps2piTkn = 1247,
     cvtsd2siTkn = 1248,
     cvtsi2sdTkn = 1249,
     cvtsi2ssTkn = 1250,
     cvtsd2ssTkn = 1251,
     cvtss2sdTkn = 1252,
     cvtss2siTkn = 1253,
     cvttpd2piTkn = 1254,
     cvttpd2dqTkn = 1255,
     cvttps2dqTkn = 1256,
     cvttps2piTkn = 1257,
     cvttsd2siTkn = 1258,
     cvttss2siTkn = 1259,
     divpdTkn = 1260,
     divpsTkn = 1261,
     divssTkn = 1262,
     divsdTkn = 1263,
     fxsaveTkn = 1264,
     fxrstorTkn = 1265,
     haddpdTkn = 1266,
     haddpsTkn = 1267,
     hsubpdTkn = 1268,
     hsubpsTkn = 1269,
     lddquTkn = 1270,
     ldmxcsrTkn = 1271,
     lfenceTkn = 1272,
     maskmovdquTkn = 1273,
     maskmovqTkn = 1274,
     maxpdTkn = 1275,
     maxpsTkn = 1276,
     maxsdTkn = 1277,
     maxssTkn = 1278,
     mfenceTkn = 1279,
     minpdTkn = 1280,
     minpsTkn = 1281,
     minsdTkn = 1282,
     minssTkn = 1283,
     monitorTkn = 1284,
     movapdTkn = 1285,
     movapsTkn = 1286,
     movddupTkn = 1287,
     movdqaTkn = 1288,
     movdquTkn = 1289,
     movdq2qTkn = 1290,
     movhlpsTkn = 1291,
     movhpdTkn = 1292,
     movhpsTkn = 1293,
     movlpdTkn = 1294,
     movlpsTkn = 1295,
     movlhpsTkn = 1296,
     movmskpdTkn = 1297,
     movmskpsTkn = 1298,
     movntpdTkn = 1299,
     movntiTkn = 1300,
     movntpsTkn = 1301,
     movntdqTkn = 1302,
     movntqTkn = 1303,
     movq2dqTkn = 1304,
     movshdupTkn = 1305,
     movsldupTkn = 1306,
     movssTkn = 1307,
     movupdTkn = 1308,
     movupsTkn = 1309,
     mulpdTkn = 1310,
     mulpsTkn = 1311,
     mulssTkn = 1312,
     mulsdTkn = 1313,
     mwaitTkn = 1314,
     orpdTkn = 1315,
     orpsTkn = 1316,
     pauseTkn = 1317,
     prefetcht0Tkn = 1318,
     prefetcht1Tkn = 1319,
     prefetcht2Tkn = 1320,
     prefetchntaTkn = 1321,
     pshufhwTkn = 1322,
     pshuflwTkn = 1323,
     psrldqTkn = 1324,
     pslldqTkn = 1325,
     rcppsTkn = 1326,
     rcpssTkn = 1327,
     rsqrtpsTkn = 1328,
     rsqrtssTkn = 1329,
     sfenceTkn = 1330,
     shufpdTkn = 1331,
     shufpsTkn = 1332,
     sqrtpdTkn = 1333,
     sqrtpsTkn = 1334,
     sqrtsdTkn = 1335,
     sqrtssTkn = 1336,
     stmxcsrTkn = 1337,
     subpsTkn = 1338,
     subpdTkn = 1339,
     subsdTkn = 1340,
     subssTkn = 1341,
     ucomisdTkn = 1342,
     ucomissTkn = 1343,
     unpckhpdTkn = 1344,
     unpckhpsTkn = 1345,
     unpcklpdTkn = 1346,
     unpcklpsTkn = 1347,
     xorpdTkn = 1348,
     xorpsTkn = 1349,
     parsePrintTkn = 1350,
     parseHLAIDTkn = 1351,
     parseClassIDTkn = 1352
   };
#endif
/* Tokens.  */
#define dupTkn 258
#define lorTkn 259
#define orTkn 260
#define landTkn 261
#define andTkn 262
#define inTkn 263
#define neTkn 264
#define geTkn 265
#define leTkn 266
#define shropTkn 267
#define shlopTkn 268
#define modTkn 269
#define divTkn 270
#define notTkn 271
#define UMINUS 272
#define intconst 273
#define hexconst 274
#define binconst 275
#define fltconst 276
#define charconst 277
#define wcharconst 278
#define strconst 279
#define wstrconst 280
#define regexconst 281
#define assignTkn 282
#define addassignTkn 283
#define subassignTkn 284
#define DotDot 285
#define coloncolonTkn 286
#define matchTkn 287
#define match2Tkn 288
#define stmtsTkn 289
#define endstmtsTkn 290
#define UndefID 291
#define RegexID 292
#define atTkn 293
#define posTkn 294
#define tabTkn 295
#define arbTkn 296
#define LocalID 297
#define LocalConstID 298
#define LocalVarID 299
#define LocalStaticID 300
#define LocalProcID 301
#define LocalIterID 302
#define LocalMethodID 303
#define LocalLabelID 304
#define NonLocalID 305
#define NonLocalConstID 306
#define NonLocalVarID 307
#define NonLocalStaticID 308
#define NonLocalProcID 309
#define NonLocalIterID 310
#define NonLocalMethodID 311
#define NonLocalLabelID 312
#define OverloadedID 313
#define ovldClassTkn 314
#define ClassVarID 315
#define ClassStaticID 316
#define ClassProcID 317
#define ClassIterID 318
#define ClassMethodID 319
#define MacroParmTkn 320
#define LastMacroParmTkn 321
#define MacroID 322
#define DoMacroDclTkn 323
#define DoRegexDclTkn 324
#define compileRegexTkn 325
#define TextParameters 326
#define DoOneValStmt 327
#define DoOneConstExpr 328
#define ctforTkn 329
#define textblockTkn 330
#define endtextTkn 331
#define stringblockTkn 332
#define endstringTkn 333
#define matchblockTkn 334
#define endmatchTkn 335
#define beginTkn 336
#define endTkn 337
#define procTkn 338
#define endprocTkn 339
#define procedureTkn 340
#define iteratorTkn 341
#define methodTkn 342
#define programTkn 343
#define unitTkn 344
#define macroTkn 345
#define keywordTkn 346
#define terminatorTkn 347
#define endmacroTkn 348
#define endMacDefTkn 349
#define regexMacroTkn 350
#define endregexTkn 351
#define endRegexDefTkn 352
#define regexReturnTkn 353
#define labelTkn 354
#define endlabelTkn 355
#define constTkn 356
#define endconstTkn 357
#define valTkn 358
#define endvalTkn 359
#define typeTkn 360
#define endtypeTkn 361
#define alignTkn 362
#define varTkn 363
#define endvarTkn 364
#define staticTkn 365
#define endstaticTkn 366
#define uninitializedTkn 367
#define endstorageTkn 368
#define readonlyTkn 369
#define endreadonlyTkn 370
#define recordTkn 371
#define endrecordTkn 372
#define unionTkn 373
#define endunionTkn 374
#define classTkn 375
#define vmtTkn 376
#define endclassTkn 377
#define enumTkn 378
#define inheritsTkn 379
#define pointerTkn 380
#define toTkn 381
#define downtoTkn 382
#define externalTkn 383
#define abstractTkn 384
#define overloadsTkn 385
#define overrideTkn 386
#define overridesTkn 387
#define forwardTkn 388
#define returnsTkn 389
#define atreturnsTkn 390
#define noframeTkn 391
#define frameTkn 392
#define nodisplayTkn 393
#define displayTkn 394
#define noalignstkTkn 395
#define alignstkTkn 396
#define alignprocTkn 397
#define useTkn 398
#define useenterTkn 399
#define noenterTkn 400
#define useleaveTkn 401
#define noleaveTkn 402
#define pascalTkn 403
#define cdeclTkn 404
#define stdcallTkn 405
#define nostorageTkn 406
#define volatileTkn 407
#define namespaceTkn 408
#define fastTkn 409
#define segmentTkn 410
#define hereTkn 411
#define atlabelTkn 412
#define nameTkn 413
#define valresTkn 414
#define resultTkn 415
#define lazyTkn 416
#define thunkTkn 417
#define jtTkn 418
#define jfTkn 419
#define ifTkn 420
#define thenTkn 421
#define elseifTkn 422
#define elseTkn 423
#define endifTkn 424
#define switchTkn 425
#define caseTkn 426
#define defaultTkn 427
#define endswitchTkn 428
#define whileTkn 429
#define doTkn 430
#define endwhileTkn 431
#define welseTkn 432
#define repeatTkn 433
#define untilTkn 434
#define forTkn 435
#define foreverTkn 436
#define foreachTkn 437
#define endforTkn 438
#define felseTkn 439
#define exitTkn 440
#define exitifTkn 441
#define breakTkn 442
#define breakifTkn 443
#define continueTkn 444
#define continueifTkn 445
#define tryTkn 446
#define alwaysTkn 447
#define unprotectedTkn 448
#define exceptionTkn 449
#define anyexceptionTkn 450
#define endtryTkn 451
#define raiseTkn 452
#define booleanTkn 453
#define int8Tkn 454
#define int16Tkn 455
#define int32Tkn 456
#define int64Tkn 457
#define int128Tkn 458
#define charTkn 459
#define wcharTkn 460
#define real32Tkn 461
#define real64Tkn 462
#define real80Tkn 463
#define real128Tkn 464
#define uns8Tkn 465
#define uns16Tkn 466
#define uns32Tkn 467
#define uns64Tkn 468
#define uns128Tkn 469
#define stringTkn 470
#define wstringTkn 471
#define zstringTkn 472
#define csetTkn 473
#define regexTkn 474
#define textTkn 475
#define byteTkn 476
#define wordTkn 477
#define dwordTkn 478
#define qwordTkn 479
#define tbyteTkn 480
#define lwordTkn 481
#define atint8Tkn 482
#define atint16Tkn 483
#define atint32Tkn 484
#define atint64Tkn 485
#define atint128Tkn 486
#define atcharTkn 487
#define atwcharTkn 488
#define atreal32Tkn 489
#define atreal64Tkn 490
#define atreal80Tkn 491
#define atuns8Tkn 492
#define atuns16Tkn 493
#define atuns32Tkn 494
#define atuns64Tkn 495
#define atuns128Tkn 496
#define atstringTkn 497
#define atwstringTkn 498
#define atcsetTkn 499
#define atbyteTkn 500
#define atwordTkn 501
#define atdwordTkn 502
#define atqwordTkn 503
#define attbyteTkn 504
#define atlwordTkn 505
#define atpointerTkn 506
#define nullTkn 507
#define absTkn 508
#define ceilTkn 509
#define cosTkn 510
#define dateTkn 511
#define envTkn 512
#define expTkn 513
#define extractTkn 514
#define floorTkn 515
#define isalphaTkn 516
#define isalphanumTkn 517
#define isdigitTkn 518
#define islowerTkn 519
#define isspaceTkn 520
#define isupperTkn 521
#define isxdigitTkn 522
#define logTkn 523
#define log10Tkn 524
#define maxTkn 525
#define minTkn 526
#define oddTkn 527
#define randomTkn 528
#define randomizeTkn 529
#define readTkn 530
#define sinTkn 531
#define sortTkn 532
#define sqrtTkn 533
#define systemTkn 534
#define tanTkn 535
#define threadTkn 536
#define timeTkn 537
#define peekcsetTkn 538
#define onecsetTkn 539
#define uptocsetTkn 540
#define zerooronecsetTkn 541
#define zeroormorecsetTkn 542
#define oneormorecsetTkn 543
#define exactlyncsetTkn 544
#define firstncsetTkn 545
#define norlesscsetTkn 546
#define normorecsetTkn 547
#define ntomcsetTkn 548
#define exactlyntomcsetTkn 549
#define peekcharTkn 550
#define onecharTkn 551
#define uptocharTkn 552
#define zerooronecharTkn 553
#define zeroormorecharTkn 554
#define oneormorecharTkn 555
#define exactlyncharTkn 556
#define firstncharTkn 557
#define norlesscharTkn 558
#define normorecharTkn 559
#define ntomcharTkn 560
#define exactlyntomcharTkn 561
#define peekicharTkn 562
#define oneicharTkn 563
#define uptoicharTkn 564
#define zerooroneicharTkn 565
#define zeroormoreicharTkn 566
#define oneormoreicharTkn 567
#define exactlynicharTkn 568
#define firstnicharTkn 569
#define norlessicharTkn 570
#define normoreicharTkn 571
#define ntomicharTkn 572
#define exactlyntomicharTkn 573
#define matchstrTkn 574
#define matchistrTkn 575
#define uptostrTkn 576
#define uptoistrTkn 577
#define matchtostrTkn 578
#define matchtoistrTkn 579
#define zeroormorewsTkn 580
#define oneormorewsTkn 581
#define wsoreosTkn 582
#define wstheneosTkn 583
#define peekwsTkn 584
#define eosTkn 585
#define wsTkn 586
#define peekstrTkn 587
#define peekistrTkn 588
#define matchidTkn 589
#define matchwordTkn 590
#define matchiwordTkn 591
#define matchintconstTkn 592
#define matchrealconstTkn 593
#define matchnumericconstTkn 594
#define matchstrconstTkn 595
#define matchregTkn 596
#define matchreg8Tkn 597
#define matchreg16Tkn 598
#define matchreg32Tkn 599
#define matchfpuregTkn 600
#define matchmmxregTkn 601
#define matchxmmregTkn 602
#define deleteTkn 603
#define indexTkn 604
#define insertTkn 605
#define lengthTkn 606
#define lowercaseTkn 607
#define replaceTkn 608
#define rindexTkn 609
#define strbrkTkn 610
#define strsetTkn 611
#define strspanTkn 612
#define substrTkn 613
#define tokenizeTkn 614
#define trimTkn 615
#define uppercaseTkn 616
#define symNameTkn 617
#define symTypeTkn 618
#define sympTypeTkn 619
#define symBasepTypeTkn 620
#define symClassTkn 621
#define symSizeTkn 622
#define symOffsetTkn 623
#define symLocalsymsTkn 624
#define symParmsTkn 625
#define symLexTkn 626
#define symArityTkn 627
#define symDimTkn 628
#define symNumelementsTkn 629
#define symDefinedTkn 630
#define symTypeNameTkn 631
#define symBaseTypeNameTkn 632
#define sympClassTkn 633
#define symStaticNameTkn 634
#define symIsExternalTkn 635
#define symIsConstTkn 636
#define symIsClassTkn 637
#define symElementSizeTkn 638
#define symIsRegTkn 639
#define symIsReg8Tkn 640
#define symIsReg16Tkn 641
#define symIsReg32Tkn 642
#define symIsfRegTkn 643
#define symIsMemTkn 644
#define symIsTypeTkn 645
#define curLexTkn 646
#define curOffsetTkn 647
#define curDirTkn 648
#define addOffset1stTkn 649
#define lineNumberTkn 650
#define lineNumberStkTkn 651
#define errorPrefixTkn 652
#define filenameTkn 653
#define fileNameStkTkn 654
#define startParmOfsTkn 655
#define startLclOfsTkn 656
#define enumSizeTkn 657
#define lastMacroObjectTkn 658
#define curObjectNameTkn 659
#define sectionTkn 660
#define boundvarTkn 661
#define intovarTkn 662
#define traceTkn 663
#define exceptsTkn 664
#define optstringsTkn 665
#define baseregTkn 666
#define st0Tkn 667
#define st1Tkn 668
#define st2Tkn 669
#define st3Tkn 670
#define st4Tkn 671
#define st5Tkn 672
#define st6Tkn 673
#define st7Tkn 674
#define alTkn 675
#define ahTkn 676
#define axTkn 677
#define eaxTkn 678
#define blTkn 679
#define bhTkn 680
#define bxTkn 681
#define ebxTkn 682
#define clTkn 683
#define chTkn 684
#define cxTkn 685
#define ecxTkn 686
#define dlTkn 687
#define dhTkn 688
#define dxTkn 689
#define edxTkn 690
#define siTkn 691
#define esiTkn 692
#define diTkn 693
#define ediTkn 694
#define bpTkn 695
#define ebpTkn 696
#define spTkn 697
#define espTkn 698
#define mm0Tkn 699
#define mm1Tkn 700
#define mm2Tkn 701
#define mm3Tkn 702
#define mm4Tkn 703
#define mm5Tkn 704
#define mm6Tkn 705
#define mm7Tkn 706
#define xmm0Tkn 707
#define xmm1Tkn 708
#define xmm2Tkn 709
#define xmm3Tkn 710
#define xmm4Tkn 711
#define xmm5Tkn 712
#define xmm6Tkn 713
#define xmm7Tkn 714
#define csTkn 715
#define dsTkn 716
#define esTkn 717
#define fsTkn 718
#define gsTkn 719
#define ssTkn 720
#define cr0Tkn 721
#define cr1Tkn 722
#define cr2Tkn 723
#define cr3Tkn 724
#define cr4Tkn 725
#define cr5Tkn 726
#define cr6Tkn 727
#define cr7Tkn 728
#define dr0Tkn 729
#define dr1Tkn 730
#define dr2Tkn 731
#define dr3Tkn 732
#define dr4Tkn 733
#define dr5Tkn 734
#define dr6Tkn 735
#define dr7Tkn 736
#define dxaxTkn 737
#define edxeaxTkn 738
#define cTkn 739
#define ncTkn 740
#define oTkn 741
#define noTkn 742
#define sTkn 743
#define nsTkn 744
#define zTkn 745
#define nzTkn 746
#define aTkn 747
#define naTkn 748
#define aeTkn 749
#define naeTkn 750
#define bTkn 751
#define nbTkn 752
#define beTkn 753
#define nbeTkn 754
#define eTkn 755
#define gTkn 756
#define ngTkn 757
#define ngeTkn 758
#define lTkn 759
#define nlTkn 760
#define nleTkn 761
#define peTkn 762
#define poTkn 763
#define npTkn 764
#define pTkn 765
#define aaaTkn 766
#define aadTkn 767
#define aamTkn 768
#define aasTkn 769
#define adcTkn 770
#define lockadcTkn 771
#define addTkn 772
#define lockaddTkn 773
#define lockandTkn 774
#define arplTkn 775
#define boundTkn 776
#define bsfTkn 777
#define bsrTkn 778
#define bswapTkn 779
#define btTkn 780
#define btcTkn 781
#define lockbtcTkn 782
#define btrTkn 783
#define lockbtrTkn 784
#define btsTkn 785
#define lockbtsTkn 786
#define callTkn 787
#define cbwTkn 788
#define cdqTkn 789
#define clcTkn 790
#define cldTkn 791
#define cliTkn 792
#define cltsTkn 793
#define cmcTkn 794
#define cmovoTkn 795
#define cmovnoTkn 796
#define cmovbTkn 797
#define cmovnbTkn 798
#define cmoveTkn 799
#define cmovneTkn 800
#define cmovbeTkn 801
#define cmovnbeTkn 802
#define cmovsTkn 803
#define cmovnsTkn 804
#define cmovpTkn 805
#define cmovnpTkn 806
#define cmovlTkn 807
#define cmovnlTkn 808
#define cmovleTkn 809
#define cmovnleTkn 810
#define cmpTkn 811
#define cmpsbTkn 812
#define cmpsdTkn 813
#define cmpswTkn 814
#define cmpxchgTkn 815
#define lockcmpxchgTkn 816
#define cmpxchg8bTkn 817
#define cpuidTkn 818
#define cwdTkn 819
#define cwdeTkn 820
#define daaTkn 821
#define dasTkn 822
#define decTkn 823
#define lockdecTkn 824
#define enterTkn 825
#define hltTkn 826
#define idivTkn 827
#define imodTkn 828
#define imulTkn 829
#define intmulTkn 830
#define incTkn 831
#define lockincTkn 832
#define insbTkn 833
#define insdTkn 834
#define inswTkn 835
#define intTkn 836
#define intoTkn 837
#define invdTkn 838
#define invlpgTkn 839
#define iretTkn 840
#define iretdTkn 841
#define jaTkn 842
#define jaeTkn 843
#define jbTkn 844
#define jbeTkn 845
#define jcTkn 846
#define jeTkn 847
#define jgTkn 848
#define jgeTkn 849
#define jlTkn 850
#define jleTkn 851
#define jnaTkn 852
#define jnaeTkn 853
#define jnbTkn 854
#define jnbeTkn 855
#define jncTkn 856
#define jneTkn 857
#define jngTkn 858
#define jngeTkn 859
#define jnlTkn 860
#define jnleTkn 861
#define jnoTkn 862
#define joTkn 863
#define jnpTkn 864
#define jnsTkn 865
#define jnzTkn 866
#define jpTkn 867
#define jpeTkn 868
#define jpoTkn 869
#define jsTkn 870
#define jzTkn 871
#define jcxzTkn 872
#define jecxzTkn 873
#define jmpTkn 874
#define lahfTkn 875
#define larTkn 876
#define leaTkn 877
#define ldsTkn 878
#define lesTkn 879
#define lfsTkn 880
#define lgsTkn 881
#define lssTkn 882
#define lslTkn 883
#define lgdtTkn 884
#define lidtTkn 885
#define lldtTkn 886
#define sgdtTkn 887
#define sidtTkn 888
#define sldtTkn 889
#define leaveTkn 890
#define lodsbTkn 891
#define lodsdTkn 892
#define lodswTkn 893
#define loopTkn 894
#define loopeTkn 895
#define loopzTkn 896
#define loopneTkn 897
#define loopnzTkn 898
#define lmswTkn 899
#define ltrTkn 900
#define strTkn 901
#define movTkn 902
#define movsbTkn 903
#define movsdTkn 904
#define movswTkn 905
#define movsxTkn 906
#define movzxTkn 907
#define mulTkn 908
#define negTkn 909
#define locknegTkn 910
#define nopTkn 911
#define locknotTkn 912
#define lockorTkn 913
#define outTkn 914
#define outsbTkn 915
#define outsdTkn 916
#define outswTkn 917
#define popTkn 918
#define popaTkn 919
#define popadTkn 920
#define popfTkn 921
#define popfdTkn 922
#define pushTkn 923
#define pushaTkn 924
#define pushadTkn 925
#define pushdTkn 926
#define pushfTkn 927
#define pushfdTkn 928
#define pushwTkn 929
#define rclTkn 930
#define rcrTkn 931
#define rdmsrTkn 932
#define rdpmcTkn 933
#define rdtscTkn 934
#define rsmTkn 935
#define repmovsbTkn 936
#define repmovswTkn 937
#define repmovsdTkn 938
#define repinsbTkn 939
#define repinswTkn 940
#define repinsdTkn 941
#define repoutsbTkn 942
#define repoutswTkn 943
#define repoutsdTkn 944
#define repstosbTkn 945
#define repstoswTkn 946
#define repstosdTkn 947
#define repecmpsbTkn 948
#define repecmpswTkn 949
#define repecmpsdTkn 950
#define repzcmpsbTkn 951
#define repzcmpswTkn 952
#define repzcmpsdTkn 953
#define repnecmpsbTkn 954
#define repnecmpswTkn 955
#define repnecmpsdTkn 956
#define repnzcmpsbTkn 957
#define repnzcmpswTkn 958
#define repnzcmpsdTkn 959
#define repescasbTkn 960
#define repescaswTkn 961
#define repescasdTkn 962
#define repnescasbTkn 963
#define repnescaswTkn 964
#define repnescasdTkn 965
#define repzscasbTkn 966
#define repzscaswTkn 967
#define repzscasdTkn 968
#define repnzscasbTkn 969
#define repnzscaswTkn 970
#define repnzscasdTkn 971
#define retTkn 972
#define rolTkn 973
#define rorTkn 974
#define sahfTkn 975
#define salTkn 976
#define sarTkn 977
#define sbbTkn 978
#define locksbbTkn 979
#define scasbTkn 980
#define scasdTkn 981
#define scaswTkn 982
#define setbTkn 983
#define setnbTkn 984
#define setzTkn 985
#define setnzTkn 986
#define setbeTkn 987
#define setnbeTkn 988
#define setoTkn 989
#define setnoTkn 990
#define setsTkn 991
#define setnsTkn 992
#define setpTkn 993
#define setnpTkn 994
#define setlTkn 995
#define setleTkn 996
#define setnlTkn 997
#define setnleTkn 998
#define shlTkn 999
#define shldTkn 1000
#define shrTkn 1001
#define shrdTkn 1002
#define smswTkn 1003
#define stcTkn 1004
#define stdTkn 1005
#define stiTkn 1006
#define stosbTkn 1007
#define stosdTkn 1008
#define stoswTkn 1009
#define subTkn 1010
#define sysenterTkn 1011
#define sysexitTkn 1012
#define locksubTkn 1013
#define testTkn 1014
#define ud2Tkn 1015
#define verrTkn 1016
#define verwTkn 1017
#define waitTkn 1018
#define wbinvdTkn 1019
#define wrmsrTkn 1020
#define xaddTkn 1021
#define lockxaddTkn 1022
#define xchgTkn 1023
#define lockxchgTkn 1024
#define xlatTkn 1025
#define xorTkn 1026
#define lockxorTkn 1027
#define fldTkn 1028
#define fildTkn 1029
#define fbldTkn 1030
#define fstTkn 1031
#define fstpTkn 1032
#define fistTkn 1033
#define fistpTkn 1034
#define fisttpTkn 1035
#define fbstpTkn 1036
#define fxchTkn 1037
#define fxamTkn 1038
#define faddTkn 1039
#define faddpTkn 1040
#define fiaddTkn 1041
#define fmulTkn 1042
#define fmulpTkn 1043
#define fimulTkn 1044
#define fsubTkn 1045
#define fsubpTkn 1046
#define fsubrTkn 1047
#define fsubrpTkn 1048
#define fisubTkn 1049
#define fisubrTkn 1050
#define fdivTkn 1051
#define fdivpTkn 1052
#define fdivrTkn 1053
#define fdivrpTkn 1054
#define fidivTkn 1055
#define fidivrTkn 1056
#define fcomTkn 1057
#define fcompTkn 1058
#define fcomppTkn 1059
#define ficomTkn 1060
#define ficompTkn 1061
#define fucomTkn 1062
#define fucompTkn 1063
#define fucomppTkn 1064
#define fsqrtTkn 1065
#define fabsTkn 1066
#define fchsTkn 1067
#define ftstTkn 1068
#define fscaleTkn 1069
#define fpremTkn 1070
#define fprem1Tkn 1071
#define frndintTkn 1072
#define fxtractTkn 1073
#define fldzTkn 1074
#define fld1Tkn 1075
#define fldpiTkn 1076
#define fldl2tTkn 1077
#define fldl2eTkn 1078
#define fldlg2Tkn 1079
#define fldln2Tkn 1080
#define f2xm1Tkn 1081
#define fsinTkn 1082
#define fcosTkn 1083
#define fsincosTkn 1084
#define fptanTkn 1085
#define fpatanTkn 1086
#define fyl2xTkn 1087
#define fyl2xp1Tkn 1088
#define finitTkn 1089
#define fninitTkn 1090
#define fwaitTkn 1091
#define fldcwTkn 1092
#define fstcwTkn 1093
#define fnstcwTkn 1094
#define fclexTkn 1095
#define fnclexTkn 1096
#define fldenvTkn 1097
#define fstenvTkn 1098
#define fnstenvTkn 1099
#define fsaveTkn 1100
#define fnsaveTkn 1101
#define frstorTkn 1102
#define fstswTkn 1103
#define fnstswTkn 1104
#define fincstpTkn 1105
#define fdecstpTkn 1106
#define fnopTkn 1107
#define ffreeTkn 1108
#define fcmovaTkn 1109
#define fcmovaeTkn 1110
#define fcmovbTkn 1111
#define fcmovbeTkn 1112
#define fcmoveTkn 1113
#define fcmovnaTkn 1114
#define fcmovnaeTkn 1115
#define fcmovnbTkn 1116
#define fcmovnbeTkn 1117
#define fcmovneTkn 1118
#define fcmovnuTkn 1119
#define fcmovuTkn 1120
#define fcomiTkn 1121
#define fcomipTkn 1122
#define fucomiTkn 1123
#define fucomipTkn 1124
#define paddbTkn 1125
#define paddwTkn 1126
#define padddTkn 1127
#define paddqTkn 1128
#define paddsbTkn 1129
#define paddswTkn 1130
#define paddusbTkn 1131
#define padduswTkn 1132
#define psubbTkn 1133
#define psubwTkn 1134
#define psubdTkn 1135
#define psubqTkn 1136
#define psubsbTkn 1137
#define psubswTkn 1138
#define psubusbTkn 1139
#define psubuswTkn 1140
#define pmullwTkn 1141
#define pmulhwTkn 1142
#define pmulhuwTkn 1143
#define pmuludqTkn 1144
#define pmaddwdTkn 1145
#define pmaxswTkn 1146
#define pmaxubTkn 1147
#define pminswTkn 1148
#define pminubTkn 1149
#define psadbwTkn 1150
#define pextrwTkn 1151
#define pinsrwTkn 1152
#define pmovmskbTkn 1153
#define pshufwTkn 1154
#define pshufdTkn 1155
#define pavgbTkn 1156
#define pavgwTkn 1157
#define pcmpeqbTkn 1158
#define pcmpeqwTkn 1159
#define pcmpeqdTkn 1160
#define pcmpgtbTkn 1161
#define pcmpgtwTkn 1162
#define pcmpgtdTkn 1163
#define packsswbTkn 1164
#define packuswbTkn 1165
#define packssdwTkn 1166
#define punpcklbwTkn 1167
#define punpcklwdTkn 1168
#define punpckldqTkn 1169
#define punpcklqdqTkn 1170
#define punpckhbwTkn 1171
#define punpckhwdTkn 1172
#define punpckhdqTkn 1173
#define punpckhqdqTkn 1174
#define pandTkn 1175
#define pandnTkn 1176
#define porTkn 1177
#define pxorTkn 1178
#define psllwTkn 1179
#define pslldTkn 1180
#define psllqTkn 1181
#define psrlwTkn 1182
#define psrldTkn 1183
#define psrlqTkn 1184
#define psrawTkn 1185
#define psradTkn 1186
#define movdTkn 1187
#define movqTkn 1188
#define emmsTkn 1189
#define addpdTkn 1190
#define addsdTkn 1191
#define addpsTkn 1192
#define addssTkn 1193
#define addsubpsTkn 1194
#define addsubpdTkn 1195
#define andnpdTkn 1196
#define andnpsTkn 1197
#define andpdTkn 1198
#define andpsTkn 1199
#define clflushTkn 1200
#define cmppdTkn 1201
#define cmppsTkn 1202
#define cmpssTkn 1203
#define cmpeqssTkn 1204
#define cmplessTkn 1205
#define cmpltssTkn 1206
#define cmpneqssTkn 1207
#define cmpnltssTkn 1208
#define cmpnlessTkn 1209
#define cmpordssTkn 1210
#define cmpunordssTkn 1211
#define cmpeqsdTkn 1212
#define cmplesdTkn 1213
#define cmpltsdTkn 1214
#define cmpneqsdTkn 1215
#define cmpnltsdTkn 1216
#define cmpnlesdTkn 1217
#define cmpordsdTkn 1218
#define cmpunordsdTkn 1219
#define cmpeqpsTkn 1220
#define cmplepsTkn 1221
#define cmpltpsTkn 1222
#define cmpneqpsTkn 1223
#define cmpnltpsTkn 1224
#define cmpnlepsTkn 1225
#define cmpordpsTkn 1226
#define cmpunordpsTkn 1227
#define cmpeqpdTkn 1228
#define cmplepdTkn 1229
#define cmpltpdTkn 1230
#define cmpneqpdTkn 1231
#define cmpnltpdTkn 1232
#define cmpnlepdTkn 1233
#define cmpordpdTkn 1234
#define cmpunordpdTkn 1235
#define comisdTkn 1236
#define comissTkn 1237
#define cvtdq2pdTkn 1238
#define cvtdq2psTkn 1239
#define cvtpd2dqTkn 1240
#define cvtpd2piTkn 1241
#define cvtpd2psTkn 1242
#define cvtpi2pdTkn 1243
#define cvtpi2psTkn 1244
#define cvtps2dqTkn 1245
#define cvtps2pdTkn 1246
#define cvtps2piTkn 1247
#define cvtsd2siTkn 1248
#define cvtsi2sdTkn 1249
#define cvtsi2ssTkn 1250
#define cvtsd2ssTkn 1251
#define cvtss2sdTkn 1252
#define cvtss2siTkn 1253
#define cvttpd2piTkn 1254
#define cvttpd2dqTkn 1255
#define cvttps2dqTkn 1256
#define cvttps2piTkn 1257
#define cvttsd2siTkn 1258
#define cvttss2siTkn 1259
#define divpdTkn 1260
#define divpsTkn 1261
#define divssTkn 1262
#define divsdTkn 1263
#define fxsaveTkn 1264
#define fxrstorTkn 1265
#define haddpdTkn 1266
#define haddpsTkn 1267
#define hsubpdTkn 1268
#define hsubpsTkn 1269
#define lddquTkn 1270
#define ldmxcsrTkn 1271
#define lfenceTkn 1272
#define maskmovdquTkn 1273
#define maskmovqTkn 1274
#define maxpdTkn 1275
#define maxpsTkn 1276
#define maxsdTkn 1277
#define maxssTkn 1278
#define mfenceTkn 1279
#define minpdTkn 1280
#define minpsTkn 1281
#define minsdTkn 1282
#define minssTkn 1283
#define monitorTkn 1284
#define movapdTkn 1285
#define movapsTkn 1286
#define movddupTkn 1287
#define movdqaTkn 1288
#define movdquTkn 1289
#define movdq2qTkn 1290
#define movhlpsTkn 1291
#define movhpdTkn 1292
#define movhpsTkn 1293
#define movlpdTkn 1294
#define movlpsTkn 1295
#define movlhpsTkn 1296
#define movmskpdTkn 1297
#define movmskpsTkn 1298
#define movntpdTkn 1299
#define movntiTkn 1300
#define movntpsTkn 1301
#define movntdqTkn 1302
#define movntqTkn 1303
#define movq2dqTkn 1304
#define movshdupTkn 1305
#define movsldupTkn 1306
#define movssTkn 1307
#define movupdTkn 1308
#define movupsTkn 1309
#define mulpdTkn 1310
#define mulpsTkn 1311
#define mulssTkn 1312
#define mulsdTkn 1313
#define mwaitTkn 1314
#define orpdTkn 1315
#define orpsTkn 1316
#define pauseTkn 1317
#define prefetcht0Tkn 1318
#define prefetcht1Tkn 1319
#define prefetcht2Tkn 1320
#define prefetchntaTkn 1321
#define pshufhwTkn 1322
#define pshuflwTkn 1323
#define psrldqTkn 1324
#define pslldqTkn 1325
#define rcppsTkn 1326
#define rcpssTkn 1327
#define rsqrtpsTkn 1328
#define rsqrtssTkn 1329
#define sfenceTkn 1330
#define shufpdTkn 1331
#define shufpsTkn 1332
#define sqrtpdTkn 1333
#define sqrtpsTkn 1334
#define sqrtsdTkn 1335
#define sqrtssTkn 1336
#define stmxcsrTkn 1337
#define subpsTkn 1338
#define subpdTkn 1339
#define subsdTkn 1340
#define subssTkn 1341
#define ucomisdTkn 1342
#define ucomissTkn 1343
#define unpckhpdTkn 1344
#define unpckhpsTkn 1345
#define unpcklpdTkn 1346
#define unpcklpsTkn 1347
#define xorpdTkn 1348
#define xorpsTkn 1349
#define parsePrintTkn 1350
#define parseHLAIDTkn 1351
#define parseClassIDTkn 1352




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 946 "hlaparse.bsn"
{
	unsigned				u;
	int						i;
	char					*idStr;
	char					*returns;
	SymNode_t				*s;
	SymNode_t				v;
	MacroType_t				m;
	struct	adrsYYS			adrs;
	struct	memYYS			mem;
	struct	adrsYYS			*adrsPtr;
	struct	regYYS			reg;
	struct	opnodeYYS		*opnode;
	struct	operandYYS		*operand;
	struct	PointerListType	*plist;
	
	struct
	{
				char	*idStr;		// Must be first!
		SymNode_t *s;
	} neID;  // For anyID ("n" "e" ID :-) )
	
	struct
	{
		int					parmCnt;
		SymNode_t			**types;
		char				*parms;
		enum	ParmForm	*pForms;
	} collectedParms;
	
	struct
	{
		int l;
		int r;
	} rr;
	
	struct
	{
		struct adrsYYS m;
		int r;
	} mr;
	
	struct
	{
		int r;
		struct adrsYYS m;
	} rm;
	

	struct
	{
		SymNode_t *s;
		SymNode_t *cns;
	}en;
	
	struct
	{
		SymNode_t 		*type;
		char			*idStr;
	}nameAndType;
	
	struct
	{
		int				ints[4];
		unsigned		unss[4];
		SymNode_t 		*syms[4];
	}save;
	
		
		
	
	// Attributes for record and unions where we can save important data.
	
	struct
	{
		SymNode_t *endFields;
		SymNode_t *base;
		SymNode_t *saveCurNS;
		SymNode_t *saveRecNS;
		SymNode_t *saveRecGlobal;
		SymNode_t *saveProcNS;
		SymNode_t *saveProcGlobal;
		int MinRecAlignment;
		int MaxRecAlignment;
		int TempRecAlign;
		int RecFieldCnt;
		int CurOffset;
		int SaveOffset;
		int SaveDir;
		int SaveAdd1st;
		int SaveLex;
		char inSave;
		char newOffset;
		
	}ru;
	
	struct
	{
		short			SpecifiedOptions;
		short			UseFrame;
		short			UseDisplay;
		short			AlignStk;
		short			Alignment;
		short			NoStorage;
		short			NoEnter;
		short			NoLeave;
		short			IsVolatile;
		enum CallSeq	CallingSequence;
		char			*returns;
		char			*use;
	}options;


	struct
	{
		int				Disp;
		char			*FullName;
		SymNode_t		*Sym;
		char			*StaticName;
	}dotName;

	struct
	{
		SymNode_t			*sym;
		SymNode_t			*type;
		unsigned			ObjectSize;
		unsigned			cls;
		unsigned			arity;
	}cls;


	struct
	{
		union
		{
			int				label1;
			int				trueTarget;
		}l1;
		union
		{
			int				label2;
			int				falseTarget;
		}l2;
		union
		{
			int				label3;
			int				exitTarget;
		}l3;
		int					label4;
		int					saveTrue;
		int					saveFalse;
		
	}labels;
	
	// The following is used when parsing #for loops.
	
	struct
	{
				SymNode_t	*ControlVar;
		union	YYSTYPE		*inVal;
				int			endVal;
				int			byVal;
		enum	PrimType	pType;
	}forInfo;
	
	struct
	{
		int		cnt;
		int		size;
		char	bytes[8];
	}opcodes;
	
	struct
	{
		int		minRange;
		int		maxRange;
		int		lazy;
	}ranges;
	
	// The following is used to process switch/case/default/endswitch statements:
	
	struct
	{
		unsigned	cnt;
		int			minval;
		int			startOfCases;
		int			defaultLbl;
		int			exitLbl;
		int			*cases;
		int			*caseLbls;
	}cases;
	
	struct
	{
		unsigned	cnt;
		int			*cases;
	} caseVals;
	
	struct
	{
		int			LineCnt;
		char		*FileName;
	} macroInvocation;
	
}
/* Line 1489 of yacc.c.  */
#line 2449 "hlaparse.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



