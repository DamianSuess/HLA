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
     rindexTkn = 608,
     strbrkTkn = 609,
     strsetTkn = 610,
     strspanTkn = 611,
     substrTkn = 612,
     tokenizeTkn = 613,
     trimTkn = 614,
     uppercaseTkn = 615,
     symNameTkn = 616,
     symTypeTkn = 617,
     sympTypeTkn = 618,
     symBasepTypeTkn = 619,
     symClassTkn = 620,
     symSizeTkn = 621,
     symOffsetTkn = 622,
     symLocalsymsTkn = 623,
     symParmsTkn = 624,
     symLexTkn = 625,
     symArityTkn = 626,
     symDimTkn = 627,
     symNumelementsTkn = 628,
     symDefinedTkn = 629,
     symTypeNameTkn = 630,
     symBaseTypeNameTkn = 631,
     sympClassTkn = 632,
     symStaticNameTkn = 633,
     symIsExternalTkn = 634,
     symIsConstTkn = 635,
     symIsClassTkn = 636,
     symElementSizeTkn = 637,
     symIsRegTkn = 638,
     symIsReg8Tkn = 639,
     symIsReg16Tkn = 640,
     symIsReg32Tkn = 641,
     symIsfRegTkn = 642,
     symIsMemTkn = 643,
     symIsTypeTkn = 644,
     curLexTkn = 645,
     curOffsetTkn = 646,
     curDirTkn = 647,
     addOffset1stTkn = 648,
     lineNumberTkn = 649,
     lineNumberStkTkn = 650,
     errorPrefixTkn = 651,
     filenameTkn = 652,
     fileNameStkTkn = 653,
     startParmOfsTkn = 654,
     startLclOfsTkn = 655,
     enumSizeTkn = 656,
     lastMacroObjectTkn = 657,
     curObjectNameTkn = 658,
     sectionTkn = 659,
     boundvarTkn = 660,
     intovarTkn = 661,
     traceTkn = 662,
     exceptsTkn = 663,
     optstringsTkn = 664,
     baseregTkn = 665,
     st0Tkn = 666,
     st1Tkn = 667,
     st2Tkn = 668,
     st3Tkn = 669,
     st4Tkn = 670,
     st5Tkn = 671,
     st6Tkn = 672,
     st7Tkn = 673,
     alTkn = 674,
     ahTkn = 675,
     axTkn = 676,
     eaxTkn = 677,
     blTkn = 678,
     bhTkn = 679,
     bxTkn = 680,
     ebxTkn = 681,
     clTkn = 682,
     chTkn = 683,
     cxTkn = 684,
     ecxTkn = 685,
     dlTkn = 686,
     dhTkn = 687,
     dxTkn = 688,
     edxTkn = 689,
     siTkn = 690,
     esiTkn = 691,
     diTkn = 692,
     ediTkn = 693,
     bpTkn = 694,
     ebpTkn = 695,
     spTkn = 696,
     espTkn = 697,
     mm0Tkn = 698,
     mm1Tkn = 699,
     mm2Tkn = 700,
     mm3Tkn = 701,
     mm4Tkn = 702,
     mm5Tkn = 703,
     mm6Tkn = 704,
     mm7Tkn = 705,
     xmm0Tkn = 706,
     xmm1Tkn = 707,
     xmm2Tkn = 708,
     xmm3Tkn = 709,
     xmm4Tkn = 710,
     xmm5Tkn = 711,
     xmm6Tkn = 712,
     xmm7Tkn = 713,
     csTkn = 714,
     dsTkn = 715,
     esTkn = 716,
     fsTkn = 717,
     gsTkn = 718,
     ssTkn = 719,
     cr0Tkn = 720,
     cr1Tkn = 721,
     cr2Tkn = 722,
     cr3Tkn = 723,
     cr4Tkn = 724,
     cr5Tkn = 725,
     cr6Tkn = 726,
     cr7Tkn = 727,
     dr0Tkn = 728,
     dr1Tkn = 729,
     dr2Tkn = 730,
     dr3Tkn = 731,
     dr4Tkn = 732,
     dr5Tkn = 733,
     dr6Tkn = 734,
     dr7Tkn = 735,
     dxaxTkn = 736,
     edxeaxTkn = 737,
     cTkn = 738,
     ncTkn = 739,
     oTkn = 740,
     noTkn = 741,
     sTkn = 742,
     nsTkn = 743,
     zTkn = 744,
     nzTkn = 745,
     aTkn = 746,
     naTkn = 747,
     aeTkn = 748,
     naeTkn = 749,
     bTkn = 750,
     nbTkn = 751,
     beTkn = 752,
     nbeTkn = 753,
     eTkn = 754,
     gTkn = 755,
     ngTkn = 756,
     ngeTkn = 757,
     lTkn = 758,
     nlTkn = 759,
     nleTkn = 760,
     peTkn = 761,
     poTkn = 762,
     npTkn = 763,
     pTkn = 764,
     aaaTkn = 765,
     aadTkn = 766,
     aamTkn = 767,
     aasTkn = 768,
     adcTkn = 769,
     lockadcTkn = 770,
     addTkn = 771,
     lockaddTkn = 772,
     lockandTkn = 773,
     arplTkn = 774,
     boundTkn = 775,
     bsfTkn = 776,
     bsrTkn = 777,
     bswapTkn = 778,
     btTkn = 779,
     btcTkn = 780,
     lockbtcTkn = 781,
     btrTkn = 782,
     lockbtrTkn = 783,
     btsTkn = 784,
     lockbtsTkn = 785,
     callTkn = 786,
     cbwTkn = 787,
     cdqTkn = 788,
     clcTkn = 789,
     cldTkn = 790,
     cliTkn = 791,
     cltsTkn = 792,
     cmcTkn = 793,
     cmovoTkn = 794,
     cmovnoTkn = 795,
     cmovbTkn = 796,
     cmovnbTkn = 797,
     cmoveTkn = 798,
     cmovneTkn = 799,
     cmovbeTkn = 800,
     cmovnbeTkn = 801,
     cmovsTkn = 802,
     cmovnsTkn = 803,
     cmovpTkn = 804,
     cmovnpTkn = 805,
     cmovlTkn = 806,
     cmovnlTkn = 807,
     cmovleTkn = 808,
     cmovnleTkn = 809,
     cmpTkn = 810,
     cmpsbTkn = 811,
     cmpsdTkn = 812,
     cmpswTkn = 813,
     cmpxchgTkn = 814,
     lockcmpxchgTkn = 815,
     cmpxchg8bTkn = 816,
     cpuidTkn = 817,
     cwdTkn = 818,
     cwdeTkn = 819,
     daaTkn = 820,
     dasTkn = 821,
     decTkn = 822,
     lockdecTkn = 823,
     enterTkn = 824,
     hltTkn = 825,
     idivTkn = 826,
     imodTkn = 827,
     imulTkn = 828,
     intmulTkn = 829,
     incTkn = 830,
     lockincTkn = 831,
     insbTkn = 832,
     insdTkn = 833,
     inswTkn = 834,
     intTkn = 835,
     intoTkn = 836,
     invdTkn = 837,
     invlpgTkn = 838,
     iretTkn = 839,
     iretdTkn = 840,
     jaTkn = 841,
     jaeTkn = 842,
     jbTkn = 843,
     jbeTkn = 844,
     jcTkn = 845,
     jeTkn = 846,
     jgTkn = 847,
     jgeTkn = 848,
     jlTkn = 849,
     jleTkn = 850,
     jnaTkn = 851,
     jnaeTkn = 852,
     jnbTkn = 853,
     jnbeTkn = 854,
     jncTkn = 855,
     jneTkn = 856,
     jngTkn = 857,
     jngeTkn = 858,
     jnlTkn = 859,
     jnleTkn = 860,
     jnoTkn = 861,
     joTkn = 862,
     jnpTkn = 863,
     jnsTkn = 864,
     jnzTkn = 865,
     jpTkn = 866,
     jpeTkn = 867,
     jpoTkn = 868,
     jsTkn = 869,
     jzTkn = 870,
     jcxzTkn = 871,
     jecxzTkn = 872,
     jmpTkn = 873,
     lahfTkn = 874,
     larTkn = 875,
     leaTkn = 876,
     ldsTkn = 877,
     lesTkn = 878,
     lfsTkn = 879,
     lgsTkn = 880,
     lssTkn = 881,
     lslTkn = 882,
     lgdtTkn = 883,
     lidtTkn = 884,
     lldtTkn = 885,
     sgdtTkn = 886,
     sidtTkn = 887,
     sldtTkn = 888,
     leaveTkn = 889,
     lodsbTkn = 890,
     lodsdTkn = 891,
     lodswTkn = 892,
     loopTkn = 893,
     loopeTkn = 894,
     loopzTkn = 895,
     loopneTkn = 896,
     loopnzTkn = 897,
     lmswTkn = 898,
     ltrTkn = 899,
     strTkn = 900,
     movTkn = 901,
     movsbTkn = 902,
     movsdTkn = 903,
     movswTkn = 904,
     movsxTkn = 905,
     movzxTkn = 906,
     mulTkn = 907,
     negTkn = 908,
     locknegTkn = 909,
     nopTkn = 910,
     locknotTkn = 911,
     lockorTkn = 912,
     outTkn = 913,
     outsbTkn = 914,
     outsdTkn = 915,
     outswTkn = 916,
     popTkn = 917,
     popaTkn = 918,
     popadTkn = 919,
     popfTkn = 920,
     popfdTkn = 921,
     pushTkn = 922,
     pushaTkn = 923,
     pushadTkn = 924,
     pushdTkn = 925,
     pushfTkn = 926,
     pushfdTkn = 927,
     pushwTkn = 928,
     rclTkn = 929,
     rcrTkn = 930,
     rdmsrTkn = 931,
     rdpmcTkn = 932,
     rdtscTkn = 933,
     rsmTkn = 934,
     repmovsbTkn = 935,
     repmovswTkn = 936,
     repmovsdTkn = 937,
     repinsbTkn = 938,
     repinswTkn = 939,
     repinsdTkn = 940,
     repoutsbTkn = 941,
     repoutswTkn = 942,
     repoutsdTkn = 943,
     repstosbTkn = 944,
     repstoswTkn = 945,
     repstosdTkn = 946,
     repecmpsbTkn = 947,
     repecmpswTkn = 948,
     repecmpsdTkn = 949,
     repzcmpsbTkn = 950,
     repzcmpswTkn = 951,
     repzcmpsdTkn = 952,
     repnecmpsbTkn = 953,
     repnecmpswTkn = 954,
     repnecmpsdTkn = 955,
     repnzcmpsbTkn = 956,
     repnzcmpswTkn = 957,
     repnzcmpsdTkn = 958,
     repescasbTkn = 959,
     repescaswTkn = 960,
     repescasdTkn = 961,
     repnescasbTkn = 962,
     repnescaswTkn = 963,
     repnescasdTkn = 964,
     repzscasbTkn = 965,
     repzscaswTkn = 966,
     repzscasdTkn = 967,
     repnzscasbTkn = 968,
     repnzscaswTkn = 969,
     repnzscasdTkn = 970,
     retTkn = 971,
     rolTkn = 972,
     rorTkn = 973,
     sahfTkn = 974,
     salTkn = 975,
     sarTkn = 976,
     sbbTkn = 977,
     locksbbTkn = 978,
     scasbTkn = 979,
     scasdTkn = 980,
     scaswTkn = 981,
     setbTkn = 982,
     setnbTkn = 983,
     setzTkn = 984,
     setnzTkn = 985,
     setbeTkn = 986,
     setnbeTkn = 987,
     setoTkn = 988,
     setnoTkn = 989,
     setsTkn = 990,
     setnsTkn = 991,
     setpTkn = 992,
     setnpTkn = 993,
     setlTkn = 994,
     setleTkn = 995,
     setnlTkn = 996,
     setnleTkn = 997,
     shlTkn = 998,
     shldTkn = 999,
     shrTkn = 1000,
     shrdTkn = 1001,
     smswTkn = 1002,
     stcTkn = 1003,
     stdTkn = 1004,
     stiTkn = 1005,
     stosbTkn = 1006,
     stosdTkn = 1007,
     stoswTkn = 1008,
     subTkn = 1009,
     sysenterTkn = 1010,
     sysexitTkn = 1011,
     locksubTkn = 1012,
     testTkn = 1013,
     ud2Tkn = 1014,
     verrTkn = 1015,
     verwTkn = 1016,
     waitTkn = 1017,
     wbinvdTkn = 1018,
     wrmsrTkn = 1019,
     xaddTkn = 1020,
     lockxaddTkn = 1021,
     xchgTkn = 1022,
     lockxchgTkn = 1023,
     xlatTkn = 1024,
     xorTkn = 1025,
     lockxorTkn = 1026,
     fldTkn = 1027,
     fildTkn = 1028,
     fbldTkn = 1029,
     fstTkn = 1030,
     fstpTkn = 1031,
     fistTkn = 1032,
     fistpTkn = 1033,
     fisttpTkn = 1034,
     fbstpTkn = 1035,
     fxchTkn = 1036,
     fxamTkn = 1037,
     faddTkn = 1038,
     faddpTkn = 1039,
     fiaddTkn = 1040,
     fmulTkn = 1041,
     fmulpTkn = 1042,
     fimulTkn = 1043,
     fsubTkn = 1044,
     fsubpTkn = 1045,
     fsubrTkn = 1046,
     fsubrpTkn = 1047,
     fisubTkn = 1048,
     fisubrTkn = 1049,
     fdivTkn = 1050,
     fdivpTkn = 1051,
     fdivrTkn = 1052,
     fdivrpTkn = 1053,
     fidivTkn = 1054,
     fidivrTkn = 1055,
     fcomTkn = 1056,
     fcompTkn = 1057,
     fcomppTkn = 1058,
     ficomTkn = 1059,
     ficompTkn = 1060,
     fucomTkn = 1061,
     fucompTkn = 1062,
     fucomppTkn = 1063,
     fsqrtTkn = 1064,
     fabsTkn = 1065,
     fchsTkn = 1066,
     ftstTkn = 1067,
     fscaleTkn = 1068,
     fpremTkn = 1069,
     fprem1Tkn = 1070,
     frndintTkn = 1071,
     fxtractTkn = 1072,
     fldzTkn = 1073,
     fld1Tkn = 1074,
     fldpiTkn = 1075,
     fldl2tTkn = 1076,
     fldl2eTkn = 1077,
     fldlg2Tkn = 1078,
     fldln2Tkn = 1079,
     f2xm1Tkn = 1080,
     fsinTkn = 1081,
     fcosTkn = 1082,
     fsincosTkn = 1083,
     fptanTkn = 1084,
     fpatanTkn = 1085,
     fyl2xTkn = 1086,
     fyl2xp1Tkn = 1087,
     finitTkn = 1088,
     fninitTkn = 1089,
     fwaitTkn = 1090,
     fldcwTkn = 1091,
     fstcwTkn = 1092,
     fnstcwTkn = 1093,
     fclexTkn = 1094,
     fnclexTkn = 1095,
     fldenvTkn = 1096,
     fstenvTkn = 1097,
     fnstenvTkn = 1098,
     fsaveTkn = 1099,
     fnsaveTkn = 1100,
     frstorTkn = 1101,
     fstswTkn = 1102,
     fnstswTkn = 1103,
     fincstpTkn = 1104,
     fdecstpTkn = 1105,
     fnopTkn = 1106,
     ffreeTkn = 1107,
     fcmovaTkn = 1108,
     fcmovaeTkn = 1109,
     fcmovbTkn = 1110,
     fcmovbeTkn = 1111,
     fcmoveTkn = 1112,
     fcmovnaTkn = 1113,
     fcmovnaeTkn = 1114,
     fcmovnbTkn = 1115,
     fcmovnbeTkn = 1116,
     fcmovneTkn = 1117,
     fcmovnuTkn = 1118,
     fcmovuTkn = 1119,
     fcomiTkn = 1120,
     fcomipTkn = 1121,
     fucomiTkn = 1122,
     fucomipTkn = 1123,
     paddbTkn = 1124,
     paddwTkn = 1125,
     padddTkn = 1126,
     paddqTkn = 1127,
     paddsbTkn = 1128,
     paddswTkn = 1129,
     paddusbTkn = 1130,
     padduswTkn = 1131,
     psubbTkn = 1132,
     psubwTkn = 1133,
     psubdTkn = 1134,
     psubqTkn = 1135,
     psubsbTkn = 1136,
     psubswTkn = 1137,
     psubusbTkn = 1138,
     psubuswTkn = 1139,
     pmullwTkn = 1140,
     pmulhwTkn = 1141,
     pmulhuwTkn = 1142,
     pmuludqTkn = 1143,
     pmaddwdTkn = 1144,
     pmaxswTkn = 1145,
     pmaxubTkn = 1146,
     pminswTkn = 1147,
     pminubTkn = 1148,
     psadbwTkn = 1149,
     pextrwTkn = 1150,
     pinsrwTkn = 1151,
     pmovmskbTkn = 1152,
     pshufwTkn = 1153,
     pshufdTkn = 1154,
     pavgbTkn = 1155,
     pavgwTkn = 1156,
     pcmpeqbTkn = 1157,
     pcmpeqwTkn = 1158,
     pcmpeqdTkn = 1159,
     pcmpgtbTkn = 1160,
     pcmpgtwTkn = 1161,
     pcmpgtdTkn = 1162,
     packsswbTkn = 1163,
     packuswbTkn = 1164,
     packssdwTkn = 1165,
     punpcklbwTkn = 1166,
     punpcklwdTkn = 1167,
     punpckldqTkn = 1168,
     punpcklqdqTkn = 1169,
     punpckhbwTkn = 1170,
     punpckhwdTkn = 1171,
     punpckhdqTkn = 1172,
     punpckhqdqTkn = 1173,
     pandTkn = 1174,
     pandnTkn = 1175,
     porTkn = 1176,
     pxorTkn = 1177,
     psllwTkn = 1178,
     pslldTkn = 1179,
     psllqTkn = 1180,
     psrlwTkn = 1181,
     psrldTkn = 1182,
     psrlqTkn = 1183,
     psrawTkn = 1184,
     psradTkn = 1185,
     movdTkn = 1186,
     movqTkn = 1187,
     emmsTkn = 1188,
     addpdTkn = 1189,
     addsdTkn = 1190,
     addpsTkn = 1191,
     addssTkn = 1192,
     addsubpsTkn = 1193,
     addsubpdTkn = 1194,
     andnpdTkn = 1195,
     andnpsTkn = 1196,
     andpdTkn = 1197,
     andpsTkn = 1198,
     clflushTkn = 1199,
     cmppdTkn = 1200,
     cmppsTkn = 1201,
     cmpssTkn = 1202,
     cmpeqssTkn = 1203,
     cmplessTkn = 1204,
     cmpltssTkn = 1205,
     cmpneqssTkn = 1206,
     cmpnltssTkn = 1207,
     cmpnlessTkn = 1208,
     cmpordssTkn = 1209,
     cmpunordssTkn = 1210,
     cmpeqsdTkn = 1211,
     cmplesdTkn = 1212,
     cmpltsdTkn = 1213,
     cmpneqsdTkn = 1214,
     cmpnltsdTkn = 1215,
     cmpnlesdTkn = 1216,
     cmpordsdTkn = 1217,
     cmpunordsdTkn = 1218,
     cmpeqpsTkn = 1219,
     cmplepsTkn = 1220,
     cmpltpsTkn = 1221,
     cmpneqpsTkn = 1222,
     cmpnltpsTkn = 1223,
     cmpnlepsTkn = 1224,
     cmpordpsTkn = 1225,
     cmpunordpsTkn = 1226,
     cmpeqpdTkn = 1227,
     cmplepdTkn = 1228,
     cmpltpdTkn = 1229,
     cmpneqpdTkn = 1230,
     cmpnltpdTkn = 1231,
     cmpnlepdTkn = 1232,
     cmpordpdTkn = 1233,
     cmpunordpdTkn = 1234,
     comisdTkn = 1235,
     comissTkn = 1236,
     cvtdq2pdTkn = 1237,
     cvtdq2psTkn = 1238,
     cvtpd2dqTkn = 1239,
     cvtpd2piTkn = 1240,
     cvtpd2psTkn = 1241,
     cvtpi2pdTkn = 1242,
     cvtpi2psTkn = 1243,
     cvtps2dqTkn = 1244,
     cvtps2pdTkn = 1245,
     cvtps2piTkn = 1246,
     cvtsd2siTkn = 1247,
     cvtsi2sdTkn = 1248,
     cvtsi2ssTkn = 1249,
     cvtsd2ssTkn = 1250,
     cvtss2sdTkn = 1251,
     cvtss2siTkn = 1252,
     cvttpd2piTkn = 1253,
     cvttpd2dqTkn = 1254,
     cvttps2dqTkn = 1255,
     cvttps2piTkn = 1256,
     cvttsd2siTkn = 1257,
     cvttss2siTkn = 1258,
     divpdTkn = 1259,
     divpsTkn = 1260,
     divssTkn = 1261,
     divsdTkn = 1262,
     fxsaveTkn = 1263,
     fxrstorTkn = 1264,
     haddpdTkn = 1265,
     haddpsTkn = 1266,
     hsubpdTkn = 1267,
     hsubpsTkn = 1268,
     lddquTkn = 1269,
     ldmxcsrTkn = 1270,
     lfenceTkn = 1271,
     maskmovdquTkn = 1272,
     maskmovqTkn = 1273,
     maxpdTkn = 1274,
     maxpsTkn = 1275,
     maxsdTkn = 1276,
     maxssTkn = 1277,
     mfenceTkn = 1278,
     minpdTkn = 1279,
     minpsTkn = 1280,
     minsdTkn = 1281,
     minssTkn = 1282,
     monitorTkn = 1283,
     movapdTkn = 1284,
     movapsTkn = 1285,
     movddupTkn = 1286,
     movdqaTkn = 1287,
     movdquTkn = 1288,
     movdq2qTkn = 1289,
     movhlpsTkn = 1290,
     movhpdTkn = 1291,
     movhpsTkn = 1292,
     movlpdTkn = 1293,
     movlpsTkn = 1294,
     movlhpsTkn = 1295,
     movmskpdTkn = 1296,
     movmskpsTkn = 1297,
     movntpdTkn = 1298,
     movntiTkn = 1299,
     movntpsTkn = 1300,
     movntdqTkn = 1301,
     movntqTkn = 1302,
     movq2dqTkn = 1303,
     movshdupTkn = 1304,
     movsldupTkn = 1305,
     movssTkn = 1306,
     movupdTkn = 1307,
     movupsTkn = 1308,
     mulpdTkn = 1309,
     mulpsTkn = 1310,
     mulssTkn = 1311,
     mulsdTkn = 1312,
     mwaitTkn = 1313,
     orpdTkn = 1314,
     orpsTkn = 1315,
     pauseTkn = 1316,
     prefetcht0Tkn = 1317,
     prefetcht1Tkn = 1318,
     prefetcht2Tkn = 1319,
     prefetchntaTkn = 1320,
     pshufhwTkn = 1321,
     pshuflwTkn = 1322,
     psrldqTkn = 1323,
     pslldqTkn = 1324,
     rcppsTkn = 1325,
     rcpssTkn = 1326,
     rsqrtpsTkn = 1327,
     rsqrtssTkn = 1328,
     sfenceTkn = 1329,
     shufpdTkn = 1330,
     shufpsTkn = 1331,
     sqrtpdTkn = 1332,
     sqrtpsTkn = 1333,
     sqrtsdTkn = 1334,
     sqrtssTkn = 1335,
     stmxcsrTkn = 1336,
     subpsTkn = 1337,
     subpdTkn = 1338,
     subsdTkn = 1339,
     subssTkn = 1340,
     ucomisdTkn = 1341,
     ucomissTkn = 1342,
     unpckhpdTkn = 1343,
     unpckhpsTkn = 1344,
     unpcklpdTkn = 1345,
     unpcklpsTkn = 1346,
     xorpdTkn = 1347,
     xorpsTkn = 1348,
     parsePrintTkn = 1349,
     parseHLAIDTkn = 1350,
     parseClassIDTkn = 1351
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
#define rindexTkn 608
#define strbrkTkn 609
#define strsetTkn 610
#define strspanTkn 611
#define substrTkn 612
#define tokenizeTkn 613
#define trimTkn 614
#define uppercaseTkn 615
#define symNameTkn 616
#define symTypeTkn 617
#define sympTypeTkn 618
#define symBasepTypeTkn 619
#define symClassTkn 620
#define symSizeTkn 621
#define symOffsetTkn 622
#define symLocalsymsTkn 623
#define symParmsTkn 624
#define symLexTkn 625
#define symArityTkn 626
#define symDimTkn 627
#define symNumelementsTkn 628
#define symDefinedTkn 629
#define symTypeNameTkn 630
#define symBaseTypeNameTkn 631
#define sympClassTkn 632
#define symStaticNameTkn 633
#define symIsExternalTkn 634
#define symIsConstTkn 635
#define symIsClassTkn 636
#define symElementSizeTkn 637
#define symIsRegTkn 638
#define symIsReg8Tkn 639
#define symIsReg16Tkn 640
#define symIsReg32Tkn 641
#define symIsfRegTkn 642
#define symIsMemTkn 643
#define symIsTypeTkn 644
#define curLexTkn 645
#define curOffsetTkn 646
#define curDirTkn 647
#define addOffset1stTkn 648
#define lineNumberTkn 649
#define lineNumberStkTkn 650
#define errorPrefixTkn 651
#define filenameTkn 652
#define fileNameStkTkn 653
#define startParmOfsTkn 654
#define startLclOfsTkn 655
#define enumSizeTkn 656
#define lastMacroObjectTkn 657
#define curObjectNameTkn 658
#define sectionTkn 659
#define boundvarTkn 660
#define intovarTkn 661
#define traceTkn 662
#define exceptsTkn 663
#define optstringsTkn 664
#define baseregTkn 665
#define st0Tkn 666
#define st1Tkn 667
#define st2Tkn 668
#define st3Tkn 669
#define st4Tkn 670
#define st5Tkn 671
#define st6Tkn 672
#define st7Tkn 673
#define alTkn 674
#define ahTkn 675
#define axTkn 676
#define eaxTkn 677
#define blTkn 678
#define bhTkn 679
#define bxTkn 680
#define ebxTkn 681
#define clTkn 682
#define chTkn 683
#define cxTkn 684
#define ecxTkn 685
#define dlTkn 686
#define dhTkn 687
#define dxTkn 688
#define edxTkn 689
#define siTkn 690
#define esiTkn 691
#define diTkn 692
#define ediTkn 693
#define bpTkn 694
#define ebpTkn 695
#define spTkn 696
#define espTkn 697
#define mm0Tkn 698
#define mm1Tkn 699
#define mm2Tkn 700
#define mm3Tkn 701
#define mm4Tkn 702
#define mm5Tkn 703
#define mm6Tkn 704
#define mm7Tkn 705
#define xmm0Tkn 706
#define xmm1Tkn 707
#define xmm2Tkn 708
#define xmm3Tkn 709
#define xmm4Tkn 710
#define xmm5Tkn 711
#define xmm6Tkn 712
#define xmm7Tkn 713
#define csTkn 714
#define dsTkn 715
#define esTkn 716
#define fsTkn 717
#define gsTkn 718
#define ssTkn 719
#define cr0Tkn 720
#define cr1Tkn 721
#define cr2Tkn 722
#define cr3Tkn 723
#define cr4Tkn 724
#define cr5Tkn 725
#define cr6Tkn 726
#define cr7Tkn 727
#define dr0Tkn 728
#define dr1Tkn 729
#define dr2Tkn 730
#define dr3Tkn 731
#define dr4Tkn 732
#define dr5Tkn 733
#define dr6Tkn 734
#define dr7Tkn 735
#define dxaxTkn 736
#define edxeaxTkn 737
#define cTkn 738
#define ncTkn 739
#define oTkn 740
#define noTkn 741
#define sTkn 742
#define nsTkn 743
#define zTkn 744
#define nzTkn 745
#define aTkn 746
#define naTkn 747
#define aeTkn 748
#define naeTkn 749
#define bTkn 750
#define nbTkn 751
#define beTkn 752
#define nbeTkn 753
#define eTkn 754
#define gTkn 755
#define ngTkn 756
#define ngeTkn 757
#define lTkn 758
#define nlTkn 759
#define nleTkn 760
#define peTkn 761
#define poTkn 762
#define npTkn 763
#define pTkn 764
#define aaaTkn 765
#define aadTkn 766
#define aamTkn 767
#define aasTkn 768
#define adcTkn 769
#define lockadcTkn 770
#define addTkn 771
#define lockaddTkn 772
#define lockandTkn 773
#define arplTkn 774
#define boundTkn 775
#define bsfTkn 776
#define bsrTkn 777
#define bswapTkn 778
#define btTkn 779
#define btcTkn 780
#define lockbtcTkn 781
#define btrTkn 782
#define lockbtrTkn 783
#define btsTkn 784
#define lockbtsTkn 785
#define callTkn 786
#define cbwTkn 787
#define cdqTkn 788
#define clcTkn 789
#define cldTkn 790
#define cliTkn 791
#define cltsTkn 792
#define cmcTkn 793
#define cmovoTkn 794
#define cmovnoTkn 795
#define cmovbTkn 796
#define cmovnbTkn 797
#define cmoveTkn 798
#define cmovneTkn 799
#define cmovbeTkn 800
#define cmovnbeTkn 801
#define cmovsTkn 802
#define cmovnsTkn 803
#define cmovpTkn 804
#define cmovnpTkn 805
#define cmovlTkn 806
#define cmovnlTkn 807
#define cmovleTkn 808
#define cmovnleTkn 809
#define cmpTkn 810
#define cmpsbTkn 811
#define cmpsdTkn 812
#define cmpswTkn 813
#define cmpxchgTkn 814
#define lockcmpxchgTkn 815
#define cmpxchg8bTkn 816
#define cpuidTkn 817
#define cwdTkn 818
#define cwdeTkn 819
#define daaTkn 820
#define dasTkn 821
#define decTkn 822
#define lockdecTkn 823
#define enterTkn 824
#define hltTkn 825
#define idivTkn 826
#define imodTkn 827
#define imulTkn 828
#define intmulTkn 829
#define incTkn 830
#define lockincTkn 831
#define insbTkn 832
#define insdTkn 833
#define inswTkn 834
#define intTkn 835
#define intoTkn 836
#define invdTkn 837
#define invlpgTkn 838
#define iretTkn 839
#define iretdTkn 840
#define jaTkn 841
#define jaeTkn 842
#define jbTkn 843
#define jbeTkn 844
#define jcTkn 845
#define jeTkn 846
#define jgTkn 847
#define jgeTkn 848
#define jlTkn 849
#define jleTkn 850
#define jnaTkn 851
#define jnaeTkn 852
#define jnbTkn 853
#define jnbeTkn 854
#define jncTkn 855
#define jneTkn 856
#define jngTkn 857
#define jngeTkn 858
#define jnlTkn 859
#define jnleTkn 860
#define jnoTkn 861
#define joTkn 862
#define jnpTkn 863
#define jnsTkn 864
#define jnzTkn 865
#define jpTkn 866
#define jpeTkn 867
#define jpoTkn 868
#define jsTkn 869
#define jzTkn 870
#define jcxzTkn 871
#define jecxzTkn 872
#define jmpTkn 873
#define lahfTkn 874
#define larTkn 875
#define leaTkn 876
#define ldsTkn 877
#define lesTkn 878
#define lfsTkn 879
#define lgsTkn 880
#define lssTkn 881
#define lslTkn 882
#define lgdtTkn 883
#define lidtTkn 884
#define lldtTkn 885
#define sgdtTkn 886
#define sidtTkn 887
#define sldtTkn 888
#define leaveTkn 889
#define lodsbTkn 890
#define lodsdTkn 891
#define lodswTkn 892
#define loopTkn 893
#define loopeTkn 894
#define loopzTkn 895
#define loopneTkn 896
#define loopnzTkn 897
#define lmswTkn 898
#define ltrTkn 899
#define strTkn 900
#define movTkn 901
#define movsbTkn 902
#define movsdTkn 903
#define movswTkn 904
#define movsxTkn 905
#define movzxTkn 906
#define mulTkn 907
#define negTkn 908
#define locknegTkn 909
#define nopTkn 910
#define locknotTkn 911
#define lockorTkn 912
#define outTkn 913
#define outsbTkn 914
#define outsdTkn 915
#define outswTkn 916
#define popTkn 917
#define popaTkn 918
#define popadTkn 919
#define popfTkn 920
#define popfdTkn 921
#define pushTkn 922
#define pushaTkn 923
#define pushadTkn 924
#define pushdTkn 925
#define pushfTkn 926
#define pushfdTkn 927
#define pushwTkn 928
#define rclTkn 929
#define rcrTkn 930
#define rdmsrTkn 931
#define rdpmcTkn 932
#define rdtscTkn 933
#define rsmTkn 934
#define repmovsbTkn 935
#define repmovswTkn 936
#define repmovsdTkn 937
#define repinsbTkn 938
#define repinswTkn 939
#define repinsdTkn 940
#define repoutsbTkn 941
#define repoutswTkn 942
#define repoutsdTkn 943
#define repstosbTkn 944
#define repstoswTkn 945
#define repstosdTkn 946
#define repecmpsbTkn 947
#define repecmpswTkn 948
#define repecmpsdTkn 949
#define repzcmpsbTkn 950
#define repzcmpswTkn 951
#define repzcmpsdTkn 952
#define repnecmpsbTkn 953
#define repnecmpswTkn 954
#define repnecmpsdTkn 955
#define repnzcmpsbTkn 956
#define repnzcmpswTkn 957
#define repnzcmpsdTkn 958
#define repescasbTkn 959
#define repescaswTkn 960
#define repescasdTkn 961
#define repnescasbTkn 962
#define repnescaswTkn 963
#define repnescasdTkn 964
#define repzscasbTkn 965
#define repzscaswTkn 966
#define repzscasdTkn 967
#define repnzscasbTkn 968
#define repnzscaswTkn 969
#define repnzscasdTkn 970
#define retTkn 971
#define rolTkn 972
#define rorTkn 973
#define sahfTkn 974
#define salTkn 975
#define sarTkn 976
#define sbbTkn 977
#define locksbbTkn 978
#define scasbTkn 979
#define scasdTkn 980
#define scaswTkn 981
#define setbTkn 982
#define setnbTkn 983
#define setzTkn 984
#define setnzTkn 985
#define setbeTkn 986
#define setnbeTkn 987
#define setoTkn 988
#define setnoTkn 989
#define setsTkn 990
#define setnsTkn 991
#define setpTkn 992
#define setnpTkn 993
#define setlTkn 994
#define setleTkn 995
#define setnlTkn 996
#define setnleTkn 997
#define shlTkn 998
#define shldTkn 999
#define shrTkn 1000
#define shrdTkn 1001
#define smswTkn 1002
#define stcTkn 1003
#define stdTkn 1004
#define stiTkn 1005
#define stosbTkn 1006
#define stosdTkn 1007
#define stoswTkn 1008
#define subTkn 1009
#define sysenterTkn 1010
#define sysexitTkn 1011
#define locksubTkn 1012
#define testTkn 1013
#define ud2Tkn 1014
#define verrTkn 1015
#define verwTkn 1016
#define waitTkn 1017
#define wbinvdTkn 1018
#define wrmsrTkn 1019
#define xaddTkn 1020
#define lockxaddTkn 1021
#define xchgTkn 1022
#define lockxchgTkn 1023
#define xlatTkn 1024
#define xorTkn 1025
#define lockxorTkn 1026
#define fldTkn 1027
#define fildTkn 1028
#define fbldTkn 1029
#define fstTkn 1030
#define fstpTkn 1031
#define fistTkn 1032
#define fistpTkn 1033
#define fisttpTkn 1034
#define fbstpTkn 1035
#define fxchTkn 1036
#define fxamTkn 1037
#define faddTkn 1038
#define faddpTkn 1039
#define fiaddTkn 1040
#define fmulTkn 1041
#define fmulpTkn 1042
#define fimulTkn 1043
#define fsubTkn 1044
#define fsubpTkn 1045
#define fsubrTkn 1046
#define fsubrpTkn 1047
#define fisubTkn 1048
#define fisubrTkn 1049
#define fdivTkn 1050
#define fdivpTkn 1051
#define fdivrTkn 1052
#define fdivrpTkn 1053
#define fidivTkn 1054
#define fidivrTkn 1055
#define fcomTkn 1056
#define fcompTkn 1057
#define fcomppTkn 1058
#define ficomTkn 1059
#define ficompTkn 1060
#define fucomTkn 1061
#define fucompTkn 1062
#define fucomppTkn 1063
#define fsqrtTkn 1064
#define fabsTkn 1065
#define fchsTkn 1066
#define ftstTkn 1067
#define fscaleTkn 1068
#define fpremTkn 1069
#define fprem1Tkn 1070
#define frndintTkn 1071
#define fxtractTkn 1072
#define fldzTkn 1073
#define fld1Tkn 1074
#define fldpiTkn 1075
#define fldl2tTkn 1076
#define fldl2eTkn 1077
#define fldlg2Tkn 1078
#define fldln2Tkn 1079
#define f2xm1Tkn 1080
#define fsinTkn 1081
#define fcosTkn 1082
#define fsincosTkn 1083
#define fptanTkn 1084
#define fpatanTkn 1085
#define fyl2xTkn 1086
#define fyl2xp1Tkn 1087
#define finitTkn 1088
#define fninitTkn 1089
#define fwaitTkn 1090
#define fldcwTkn 1091
#define fstcwTkn 1092
#define fnstcwTkn 1093
#define fclexTkn 1094
#define fnclexTkn 1095
#define fldenvTkn 1096
#define fstenvTkn 1097
#define fnstenvTkn 1098
#define fsaveTkn 1099
#define fnsaveTkn 1100
#define frstorTkn 1101
#define fstswTkn 1102
#define fnstswTkn 1103
#define fincstpTkn 1104
#define fdecstpTkn 1105
#define fnopTkn 1106
#define ffreeTkn 1107
#define fcmovaTkn 1108
#define fcmovaeTkn 1109
#define fcmovbTkn 1110
#define fcmovbeTkn 1111
#define fcmoveTkn 1112
#define fcmovnaTkn 1113
#define fcmovnaeTkn 1114
#define fcmovnbTkn 1115
#define fcmovnbeTkn 1116
#define fcmovneTkn 1117
#define fcmovnuTkn 1118
#define fcmovuTkn 1119
#define fcomiTkn 1120
#define fcomipTkn 1121
#define fucomiTkn 1122
#define fucomipTkn 1123
#define paddbTkn 1124
#define paddwTkn 1125
#define padddTkn 1126
#define paddqTkn 1127
#define paddsbTkn 1128
#define paddswTkn 1129
#define paddusbTkn 1130
#define padduswTkn 1131
#define psubbTkn 1132
#define psubwTkn 1133
#define psubdTkn 1134
#define psubqTkn 1135
#define psubsbTkn 1136
#define psubswTkn 1137
#define psubusbTkn 1138
#define psubuswTkn 1139
#define pmullwTkn 1140
#define pmulhwTkn 1141
#define pmulhuwTkn 1142
#define pmuludqTkn 1143
#define pmaddwdTkn 1144
#define pmaxswTkn 1145
#define pmaxubTkn 1146
#define pminswTkn 1147
#define pminubTkn 1148
#define psadbwTkn 1149
#define pextrwTkn 1150
#define pinsrwTkn 1151
#define pmovmskbTkn 1152
#define pshufwTkn 1153
#define pshufdTkn 1154
#define pavgbTkn 1155
#define pavgwTkn 1156
#define pcmpeqbTkn 1157
#define pcmpeqwTkn 1158
#define pcmpeqdTkn 1159
#define pcmpgtbTkn 1160
#define pcmpgtwTkn 1161
#define pcmpgtdTkn 1162
#define packsswbTkn 1163
#define packuswbTkn 1164
#define packssdwTkn 1165
#define punpcklbwTkn 1166
#define punpcklwdTkn 1167
#define punpckldqTkn 1168
#define punpcklqdqTkn 1169
#define punpckhbwTkn 1170
#define punpckhwdTkn 1171
#define punpckhdqTkn 1172
#define punpckhqdqTkn 1173
#define pandTkn 1174
#define pandnTkn 1175
#define porTkn 1176
#define pxorTkn 1177
#define psllwTkn 1178
#define pslldTkn 1179
#define psllqTkn 1180
#define psrlwTkn 1181
#define psrldTkn 1182
#define psrlqTkn 1183
#define psrawTkn 1184
#define psradTkn 1185
#define movdTkn 1186
#define movqTkn 1187
#define emmsTkn 1188
#define addpdTkn 1189
#define addsdTkn 1190
#define addpsTkn 1191
#define addssTkn 1192
#define addsubpsTkn 1193
#define addsubpdTkn 1194
#define andnpdTkn 1195
#define andnpsTkn 1196
#define andpdTkn 1197
#define andpsTkn 1198
#define clflushTkn 1199
#define cmppdTkn 1200
#define cmppsTkn 1201
#define cmpssTkn 1202
#define cmpeqssTkn 1203
#define cmplessTkn 1204
#define cmpltssTkn 1205
#define cmpneqssTkn 1206
#define cmpnltssTkn 1207
#define cmpnlessTkn 1208
#define cmpordssTkn 1209
#define cmpunordssTkn 1210
#define cmpeqsdTkn 1211
#define cmplesdTkn 1212
#define cmpltsdTkn 1213
#define cmpneqsdTkn 1214
#define cmpnltsdTkn 1215
#define cmpnlesdTkn 1216
#define cmpordsdTkn 1217
#define cmpunordsdTkn 1218
#define cmpeqpsTkn 1219
#define cmplepsTkn 1220
#define cmpltpsTkn 1221
#define cmpneqpsTkn 1222
#define cmpnltpsTkn 1223
#define cmpnlepsTkn 1224
#define cmpordpsTkn 1225
#define cmpunordpsTkn 1226
#define cmpeqpdTkn 1227
#define cmplepdTkn 1228
#define cmpltpdTkn 1229
#define cmpneqpdTkn 1230
#define cmpnltpdTkn 1231
#define cmpnlepdTkn 1232
#define cmpordpdTkn 1233
#define cmpunordpdTkn 1234
#define comisdTkn 1235
#define comissTkn 1236
#define cvtdq2pdTkn 1237
#define cvtdq2psTkn 1238
#define cvtpd2dqTkn 1239
#define cvtpd2piTkn 1240
#define cvtpd2psTkn 1241
#define cvtpi2pdTkn 1242
#define cvtpi2psTkn 1243
#define cvtps2dqTkn 1244
#define cvtps2pdTkn 1245
#define cvtps2piTkn 1246
#define cvtsd2siTkn 1247
#define cvtsi2sdTkn 1248
#define cvtsi2ssTkn 1249
#define cvtsd2ssTkn 1250
#define cvtss2sdTkn 1251
#define cvtss2siTkn 1252
#define cvttpd2piTkn 1253
#define cvttpd2dqTkn 1254
#define cvttps2dqTkn 1255
#define cvttps2piTkn 1256
#define cvttsd2siTkn 1257
#define cvttss2siTkn 1258
#define divpdTkn 1259
#define divpsTkn 1260
#define divssTkn 1261
#define divsdTkn 1262
#define fxsaveTkn 1263
#define fxrstorTkn 1264
#define haddpdTkn 1265
#define haddpsTkn 1266
#define hsubpdTkn 1267
#define hsubpsTkn 1268
#define lddquTkn 1269
#define ldmxcsrTkn 1270
#define lfenceTkn 1271
#define maskmovdquTkn 1272
#define maskmovqTkn 1273
#define maxpdTkn 1274
#define maxpsTkn 1275
#define maxsdTkn 1276
#define maxssTkn 1277
#define mfenceTkn 1278
#define minpdTkn 1279
#define minpsTkn 1280
#define minsdTkn 1281
#define minssTkn 1282
#define monitorTkn 1283
#define movapdTkn 1284
#define movapsTkn 1285
#define movddupTkn 1286
#define movdqaTkn 1287
#define movdquTkn 1288
#define movdq2qTkn 1289
#define movhlpsTkn 1290
#define movhpdTkn 1291
#define movhpsTkn 1292
#define movlpdTkn 1293
#define movlpsTkn 1294
#define movlhpsTkn 1295
#define movmskpdTkn 1296
#define movmskpsTkn 1297
#define movntpdTkn 1298
#define movntiTkn 1299
#define movntpsTkn 1300
#define movntdqTkn 1301
#define movntqTkn 1302
#define movq2dqTkn 1303
#define movshdupTkn 1304
#define movsldupTkn 1305
#define movssTkn 1306
#define movupdTkn 1307
#define movupsTkn 1308
#define mulpdTkn 1309
#define mulpsTkn 1310
#define mulssTkn 1311
#define mulsdTkn 1312
#define mwaitTkn 1313
#define orpdTkn 1314
#define orpsTkn 1315
#define pauseTkn 1316
#define prefetcht0Tkn 1317
#define prefetcht1Tkn 1318
#define prefetcht2Tkn 1319
#define prefetchntaTkn 1320
#define pshufhwTkn 1321
#define pshuflwTkn 1322
#define psrldqTkn 1323
#define pslldqTkn 1324
#define rcppsTkn 1325
#define rcpssTkn 1326
#define rsqrtpsTkn 1327
#define rsqrtssTkn 1328
#define sfenceTkn 1329
#define shufpdTkn 1330
#define shufpsTkn 1331
#define sqrtpdTkn 1332
#define sqrtpsTkn 1333
#define sqrtsdTkn 1334
#define sqrtssTkn 1335
#define stmxcsrTkn 1336
#define subpsTkn 1337
#define subpdTkn 1338
#define subsdTkn 1339
#define subssTkn 1340
#define ucomisdTkn 1341
#define ucomissTkn 1342
#define unpckhpdTkn 1343
#define unpckhpsTkn 1344
#define unpcklpdTkn 1345
#define unpcklpsTkn 1346
#define xorpdTkn 1347
#define xorpsTkn 1348
#define parsePrintTkn 1349
#define parseHLAIDTkn 1350
#define parseClassIDTkn 1351




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
#line 2447 "hlaparse.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



