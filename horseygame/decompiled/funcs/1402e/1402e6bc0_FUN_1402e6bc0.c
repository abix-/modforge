// Address: 0x1402e6bc0
// Ghidra name: FUN_1402e6bc0
// ============ 0x1402e6bc0 FUN_1402e6bc0 (size=385) ============


ulonglong FUN_1402e6bc0(undefined1 (*param_1) [32],ulonglong param_2)



{

  undefined1 auVar1 [32];

  undefined1 (*pauVar2) [32];

  ulonglong uVar3;

  undefined1 (*pauVar4) [32];

  ulonglong uVar5;

  undefined1 auVar6 [16];

  

  if (4 < DAT_1403e8ad0) {

    uVar3 = (ulonglong)((uint)param_1 & 0x1f);

    uVar5 = 0;

    if (uVar3 != 0) {

      uVar5 = 0x20 - uVar3;

    }

    if (param_2 < uVar5) {

      uVar5 = param_2;

    }

    for (pauVar2 = param_1;

        (pauVar2 != (undefined1 (*) [32])(*param_1 + uVar5) && ((*pauVar2)[0] != '\0'));

        pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1)) {

    }

    uVar3 = (longlong)pauVar2 - (longlong)param_1;

    if (uVar3 == uVar5) {

      pauVar4 = (undefined1 (*) [32])

                ((longlong)pauVar2 +

                ((param_2 - uVar5) - (ulonglong)((uint)(param_2 - uVar5) & 0x1f)));

      while ((pauVar2 != pauVar4 &&

             (auVar1 = vpcmpeqb_avx2(SUB6432(ZEXT1664((undefined1  [16])0x0),0),*pauVar2),

             (((((((((((((((((((((((((((((((SUB321(auVar1 >> 7,0) & 1) == 0 &&

                                          (SUB321(auVar1 >> 0xf,0) & 1) == 0) &&

                                         (SUB321(auVar1 >> 0x17,0) & 1) == 0) &&

                                        (SUB321(auVar1 >> 0x1f,0) & 1) == 0) &&

                                       (SUB321(auVar1 >> 0x27,0) & 1) == 0) &&

                                      (SUB321(auVar1 >> 0x2f,0) & 1) == 0) &&

                                     (SUB321(auVar1 >> 0x37,0) & 1) == 0) &&

                                    (SUB321(auVar1 >> 0x3f,0) & 1) == 0) &&

                                   (SUB321(auVar1 >> 0x47,0) & 1) == 0) &&

                                  (SUB321(auVar1 >> 0x4f,0) & 1) == 0) &&

                                 (SUB321(auVar1 >> 0x57,0) & 1) == 0) &&

                                (SUB321(auVar1 >> 0x5f,0) & 1) == 0) &&

                               (SUB321(auVar1 >> 0x67,0) & 1) == 0) &&

                              (SUB321(auVar1 >> 0x6f,0) & 1) == 0) &&

                             (SUB321(auVar1 >> 0x77,0) & 1) == 0) &&

                            SUB321(auVar1 >> 0x7f,0) == '\0') && (SUB321(auVar1 >> 0x87,0) & 1) == 0

                           ) && (SUB321(auVar1 >> 0x8f,0) & 1) == 0) &&

                         (SUB321(auVar1 >> 0x97,0) & 1) == 0) && (SUB321(auVar1 >> 0x9f,0) & 1) == 0

                        ) && (SUB321(auVar1 >> 0xa7,0) & 1) == 0) &&

                      (SUB321(auVar1 >> 0xaf,0) & 1) == 0) && (SUB321(auVar1 >> 0xb7,0) & 1) == 0)

                    && SUB321(auVar1 >> 0xbf,0) == '\0') && (SUB321(auVar1 >> 199,0) & 1) == 0) &&

                  (SUB321(auVar1 >> 0xcf,0) & 1) == 0) && (SUB321(auVar1 >> 0xd7,0) & 1) == 0) &&

                (SUB321(auVar1 >> 0xdf,0) & 1) == 0) && (SUB321(auVar1 >> 0xe7,0) & 1) == 0) &&

              (SUB321(auVar1 >> 0xef,0) & 1) == 0) && (SUB321(auVar1 >> 0xf7,0) & 1) == 0) &&

             -1 < auVar1[0x1f]))) {

        pauVar2 = pauVar2 + 1;

      }

      for (; (pauVar2 != (undefined1 (*) [32])(*param_1 + param_2) && ((*pauVar2)[0] != '\0'));

          pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1)) {

      }

      uVar3 = (longlong)pauVar2 - (longlong)param_1;

    }

    return uVar3;

  }

  pauVar2 = param_1;

  if (DAT_1403e8ad0 < 1) {

    for (; (pauVar2 != (undefined1 (*) [32])(*param_1 + param_2) && ((*pauVar2)[0] != '\0'));

        pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1)) {

    }

  }

  else {

    uVar3 = (ulonglong)((uint)param_1 & 0xf);

    uVar5 = 0;

    if (uVar3 != 0) {

      uVar5 = 0x10 - uVar3;

    }

    if (param_2 < uVar5) {

      uVar5 = param_2;

    }

    for (; (pauVar2 != (undefined1 (*) [32])(*param_1 + uVar5) && ((*pauVar2)[0] != '\0'));

        pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1)) {

    }

    if ((longlong)pauVar2 - (longlong)param_1 != uVar5) {

      return (longlong)pauVar2 - (longlong)param_1;

    }

    pauVar4 = (undefined1 (*) [32])

              ((longlong)pauVar2 + ((param_2 - uVar5) - (ulonglong)((uint)(param_2 - uVar5) & 0xf)))

    ;

    while ((pauVar2 != pauVar4 &&

           (auVar6[0] = -((*pauVar2)[0] == '\0'), auVar6[1] = -((*pauVar2)[1] == '\0'),

           auVar6[2] = -((*pauVar2)[2] == '\0'), auVar6[3] = -((*pauVar2)[3] == '\0'),

           auVar6[4] = -((*pauVar2)[4] == '\0'), auVar6[5] = -((*pauVar2)[5] == '\0'),

           auVar6[6] = -((*pauVar2)[6] == '\0'), auVar6[7] = -((*pauVar2)[7] == '\0'),

           auVar6[8] = -((*pauVar2)[8] == '\0'), auVar6[9] = -((*pauVar2)[9] == '\0'),

           auVar6[10] = -((*pauVar2)[10] == '\0'), auVar6[0xb] = -((*pauVar2)[0xb] == '\0'),

           auVar6[0xc] = -((*pauVar2)[0xc] == '\0'), auVar6[0xd] = -((*pauVar2)[0xd] == '\0'),

           auVar6[0xe] = -((*pauVar2)[0xe] == '\0'), auVar6[0xf] = -((*pauVar2)[0xf] == '\0'),

           (((((((((((((((SUB161(auVar6 >> 7,0) & 1) == 0 && (SUB161(auVar6 >> 0xf,0) & 1) == 0) &&

                       (SUB161(auVar6 >> 0x17,0) & 1) == 0) && (SUB161(auVar6 >> 0x1f,0) & 1) == 0)

                     && (SUB161(auVar6 >> 0x27,0) & 1) == 0) && (SUB161(auVar6 >> 0x2f,0) & 1) == 0)

                   && (SUB161(auVar6 >> 0x37,0) & 1) == 0) && (SUB161(auVar6 >> 0x3f,0) & 1) == 0)

                 && (SUB161(auVar6 >> 0x47,0) & 1) == 0) && (SUB161(auVar6 >> 0x4f,0) & 1) == 0) &&

               (SUB161(auVar6 >> 0x57,0) & 1) == 0) && (SUB161(auVar6 >> 0x5f,0) & 1) == 0) &&

             (SUB161(auVar6 >> 0x67,0) & 1) == 0) && (SUB161(auVar6 >> 0x6f,0) & 1) == 0) &&

           (SUB161(auVar6 >> 0x77,0) & 1) == 0) && -1 < auVar6[0xf]))) {

      pauVar2 = (undefined1 (*) [32])(*pauVar2 + 0x10);

    }

    if (pauVar2 != (undefined1 (*) [32])(*param_1 + param_2)) {

      while ((*pauVar2)[0] != '\0') {

        pauVar2 = (undefined1 (*) [32])(*pauVar2 + 1);

        if (pauVar2 == (undefined1 (*) [32])(*param_1 + param_2)) {

          return (longlong)pauVar2 - (longlong)param_1;

        }

      }

    }

  }

  return (longlong)pauVar2 - (longlong)param_1;

}




