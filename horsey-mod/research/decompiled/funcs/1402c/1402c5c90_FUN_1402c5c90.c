// Address: 0x1402c5c90
// Ghidra name: FUN_1402c5c90
// ============ 0x1402c5c90 FUN_1402c5c90 (size=978) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined1 (*) [16]

FUN_1402c5c90(undefined1 (*param_1) [16],undefined1 (*param_2) [16],undefined1 (*param_3) [16],

             ulonglong param_4)



{

  uint uVar1;

  byte *pbVar2;

  undefined1 *puVar3;

  char cVar4;

  uint uVar5;

  int iVar6;

  undefined1 (*pauVar7) [16];

  char *pcVar8;

  undefined1 (*pauVar9) [16];

  uint uVar10;

  longlong lVar11;

  uint uVar12;

  ulonglong uVar13;

  uint uVar14;

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  uint uVar20;

  undefined1 auVar19 [16];

  undefined1 auStack_e8 [32];

  uint local_c8 [2];

  undefined1 (*local_c0) [16];

  undefined1 (*local_b8) [16];

  undefined1 (**local_a8 [2]) [16];

  undefined1 local_98 [16];

  undefined1 (*local_88) [16];

  ulonglong local_80;

  undefined1 (*local_78) [16];

  undefined8 uStack_70;

  ulonglong local_68;

  

  local_68 = DAT_1403e8b00 ^ (ulonglong)auStack_e8;

  local_c0 = param_2;

  local_b8 = param_1;

  if (param_4 != 0) {

    if (param_4 == 1) {

      pauVar7 = (undefined1 (*) [16])FUN_1402c6070(param_1,param_2,(*param_3)[0]);

      return pauVar7;

    }

    uVar13 = (longlong)param_2 - (longlong)param_1;

    if (param_4 <= uVar13) {

      if (((DAT_1403e8ad4 >> 2 & 1) == 0) || (uVar13 < 0x10)) {

        param_2 = (undefined1 (*) [16])((longlong)param_2 - param_4);

        lVar11 = (longlong)param_3 - (longlong)param_2;

        while( true ) {

          if ((*param_2)[0] == (*param_3)[0]) {

            pcVar8 = *param_2 + 1;

            while (*pcVar8 == pcVar8[lVar11]) {

              pcVar8 = pcVar8 + 1;

              if ((longlong)pcVar8 - (longlong)param_2 == param_4) {

                return param_2;

              }

            }

          }

          if (param_2 == param_1) break;

          param_2 = (undefined1 (*) [16])(param_2[-1] + 0xf);

          lVar11 = lVar11 + 1;

        }

      }

      else if (param_4 < 0x11) {

        uVar12 = (uint)uVar13 & 0xf;

        uVar14 = (1 << (0x11U - (char)param_4 & 0x1f)) - 1;

        puVar3 = *param_1;

        FUN_1402f8e20(&local_78,param_3,param_4);

        auVar17._8_8_ = uStack_70;

        auVar17._0_8_ = local_78;

        pauVar7 = local_c0 + -1;

        auVar15 = pcmpestrm(auVar17,*pauVar7,0xc);

        uVar5 = auVar15._0_4_ & uVar14;

        if (uVar5 != 0) {

          uVar12 = 0x1f;

          if (uVar5 != 0) {

            for (; uVar5 >> uVar12 == 0; uVar12 = uVar12 - 1) {

            }

          }

          return (undefined1 (*) [16])(*pauVar7 + uVar12);

        }

        uVar5 = (uint)((ulonglong)local_78 >> 0x20);

        uVar20 = (uint)((ulonglong)uStack_70 >> 0x20);

        if (pauVar7 != (undefined1 (*) [16])(puVar3 + uVar12)) {

          do {

            pauVar7 = pauVar7 + -1;

            auVar15 = pcmpestrm(auVar17,*pauVar7,0xc);

            uVar10 = auVar15._0_4_;

            if (uVar10 != 0) {

              local_c8[0] = (uVar14 ^ 0xffff) & uVar10;

              if (local_c8[0] != 0) {

                auVar15 = *(undefined1 (*) [16])(&DAT_140386150 + -param_4);

                do {

                  uVar1 = 0x1f;

                  if (local_c8[0] != 0) {

                    for (; local_c8[0] >> uVar1 == 0; uVar1 = uVar1 - 1) {

                    }

                  }

                  pauVar9 = (undefined1 (*) [16])(*pauVar7 + uVar1);

                  auVar16._0_4_ = *(uint *)*pauVar9 ^ (uint)local_78;

                  auVar16._4_4_ = *(uint *)(*pauVar9 + 4) ^ uVar5;

                  auVar16._8_4_ = *(uint *)(*pauVar9 + 8) ^ (uint)uStack_70;

                  auVar16._12_4_ = *(uint *)(*pauVar9 + 0xc) ^ uVar20;

                  if ((auVar15 & auVar16) == (undefined1  [16])0x0) {

                    return pauVar9;

                  }

                  pbVar2 = (byte *)((longlong)local_c8 + ((longlong)(int)uVar1 >> 3));

                  *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));

                } while (local_c8[0] != 0);

              }

              uVar10 = uVar10 & uVar14;

              if (uVar10 != 0) {

                uVar5 = 0x1f;

                if (uVar10 != 0) {

                  for (; uVar10 >> uVar5 == 0; uVar5 = uVar5 - 1) {

                  }

                }

                return (undefined1 (*) [16])(*pauVar7 + uVar5);

              }

            }

            param_1 = local_b8;

          } while (pauVar7 != (undefined1 (*) [16])(puVar3 + uVar12));

        }

        if ((ulonglong)uVar12 != 0) {

          auVar17 = pcmpestrm(auVar17,*param_1,0xc);

          uVar12 = auVar17._0_4_ & (1 << (sbyte)uVar12) - 1U;

          if (uVar12 != 0) {

            local_c8[0] = (uVar14 ^ 0xffff) & uVar12;

            if (local_c8[0] != 0) {

              auVar17 = *(undefined1 (*) [16])(&DAT_140386150 + -param_4);

              do {

                uVar10 = 0x1f;

                if (local_c8[0] != 0) {

                  for (; local_c8[0] >> uVar10 == 0; uVar10 = uVar10 - 1) {

                  }

                }

                pauVar7 = (undefined1 (*) [16])(*param_1 + uVar10);

                auVar15._0_4_ = *(uint *)*pauVar7 ^ (uint)local_78;

                auVar15._4_4_ = *(uint *)(*pauVar7 + 4) ^ uVar5;

                auVar15._8_4_ = *(uint *)(*pauVar7 + 8) ^ (uint)uStack_70;

                auVar15._12_4_ = *(uint *)(*pauVar7 + 0xc) ^ uVar20;

                if ((auVar17 & auVar15) == (undefined1  [16])0x0) {

                  return pauVar7;

                }

                pbVar2 = (byte *)((longlong)local_c8 + ((longlong)(int)uVar10 >> 3));

                *pbVar2 = *pbVar2 & ~('\x01' << (uVar10 & 7));

              } while (local_c8[0] != 0);

            }

            uVar12 = uVar12 & uVar14;

            if (uVar12 != 0) {

              uVar5 = 0x1f;

              if (uVar12 != 0) {

                for (; uVar12 >> uVar5 == 0; uVar5 = uVar5 - 1) {

                }

              }

              return (undefined1 (*) [16])(*param_1 + uVar5);

            }

          }

        }

      }

      else {

        auVar17 = *param_3;

        uVar5 = (uint)uVar13 - (int)param_4;

        local_80 = param_4;

        param_3 = param_3 + 1;

        local_98 = auVar17;

        local_88 = param_3;

        param_2 = (undefined1 (*) [16])((longlong)param_2 - param_4);

        local_a8[0] = &local_78;

        auVar18._0_4_ = *(uint *)*param_2 ^ auVar17._0_4_;

        auVar18._4_4_ = *(uint *)(*param_2 + 4) ^ auVar17._4_4_;

        auVar18._8_4_ = *(uint *)(*param_2 + 8) ^ auVar17._8_4_;

        auVar18._12_4_ = *(uint *)(*param_2 + 0xc) ^ auVar17._12_4_;

        pauVar7 = param_1;

        if ((auVar18 == (undefined1  [16])0x0) &&

           (local_78 = param_2, iVar6 = memcmp(param_2 + 1,param_3,param_4 - 0x10),

           pauVar7 = param_1, iVar6 == 0)) {

          return param_2;

        }

        while (local_78 = pauVar7, param_2 != (undefined1 (*) [16])(*param_1 + (uVar5 & 0xf))) {

          param_2 = param_2 + -1;

          local_78 = param_2;

          auVar15 = pcmpestrm(auVar17,*param_2,0xc);

          pauVar7 = local_b8;

          if (auVar15._0_4_ != 0) {

            local_c8[0] = auVar15._0_4_;

            do {

              uVar12 = 0x1f;

              if (local_c8[0] != 0) {

                for (; local_c8[0] >> uVar12 == 0; uVar12 = uVar12 - 1) {

                }

              }

              pauVar7 = param_2;

              if (((uVar12 == 0) ||

                  (pauVar7 = (undefined1 (*) [16])(*param_2 + uVar12),

                  auVar19._0_4_ = auVar17._0_4_ ^ *(uint *)*pauVar7,

                  auVar19._4_4_ = auVar17._4_4_ ^ *(uint *)(*pauVar7 + 4),

                  auVar19._8_4_ = auVar17._8_4_ ^ *(uint *)(*pauVar7 + 8),

                  auVar19._12_4_ = auVar17._12_4_ ^ *(uint *)(*pauVar7 + 0xc),

                  auVar19 == (undefined1  [16])0x0)) &&

                 (iVar6 = memcmp(pauVar7 + 1,param_3,param_4 - 0x10), iVar6 == 0)) {

                return pauVar7;

              }

              pbVar2 = (byte *)((longlong)local_c8 + ((longlong)(int)uVar12 >> 3));

              *pbVar2 = *pbVar2 & ~('\x01' << (uVar12 & 7));

              pauVar7 = local_b8;

            } while (local_c8[0] != 0);

          }

        }

        uVar5 = uVar5 & 0xf;

        if (((uVar5 != 0) &&

            (auVar17 = pcmpestrm(auVar17,*local_78,0xc),

            (auVar17._0_4_ & (1 << (sbyte)uVar5) - 1U) != 0)) &&

           (cVar4 = FUN_1402c6950(local_a8), cVar4 != '\0')) {

          return local_78;

        }

      }

    }

  }

  return local_c0;

}




