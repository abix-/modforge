// Address: 0x1402d5404
// Ghidra name: FUN_1402d5404
// ============ 0x1402d5404 FUN_1402d5404 (size=429) ============


ulonglong FUN_1402d5404(byte *param_1)



{

  ushort uVar1;

  short sVar2;

  longlong lVar3;

  short *psVar4;

  ulonglong uVar5;

  short *psVar6;

  

  uVar1 = *(ushort *)(param_1 + 0x3a);

  psVar6 = (short *)(ulonglong)uVar1;

  if (uVar1 == 0x46) {

    if ((*param_1 & 8) == 0) {

      param_1[0x24] = 7;

      uVar5 = FUN_1402d6558();

      return uVar5;

    }

  }

  else if (uVar1 == 0x4e) {

    if ((*param_1 & 8) == 0) {

      param_1[0x24] = 8;

LAB_1402d543b:

      lVar3 = *(longlong *)(param_1 + 8);

      *(undefined1 *)(lVar3 + 0x30) = 1;

      *(undefined4 *)(lVar3 + 0x2c) = 0x16;

      uVar5 = FUN_1402cd39c(0,0,0,0,0,*(undefined8 *)(param_1 + 8));

      return uVar5 & 0xffffffffffffff00;

    }

  }

  else {

    if (*(int *)(param_1 + 0x34) != 0) goto LAB_1402d543b;

    if (uVar1 == 0x49) {

      psVar4 = *(short **)(param_1 + 0x10);

      sVar2 = *psVar4;

      if ((sVar2 == 0x33) && (psVar4[1] == 0x32)) {

        psVar6 = psVar4 + 2;

        param_1[0x34] = 10;

        param_1[0x35] = 0;

        param_1[0x36] = 0;

        param_1[0x37] = 0;

        *(short **)(param_1 + 0x10) = psVar6;

      }

      else if (sVar2 == 0x36) {

        psVar6 = (short *)0x0;

        if (psVar4[1] == 0x34) {

          psVar6 = psVar4 + 2;

          param_1[0x34] = 0xb;

          param_1[0x35] = 0;

          param_1[0x36] = 0;

          param_1[0x37] = 0;

          *(short **)(param_1 + 0x10) = psVar6;

        }

      }

      else {

        psVar6 = (short *)(ulonglong)(ushort)(sVar2 - 0x58U);

        if (((ushort)(sVar2 - 0x58U) < 0x21) &&

           ((0x120821001U >> ((ulonglong)psVar6 & 0x3f) & 1) != 0)) {

          param_1[0x34] = 9;

          param_1[0x35] = 0;

          param_1[0x36] = 0;

          param_1[0x37] = 0;

        }

      }

    }

    else if (uVar1 == 0x4c) {

      param_1[0x34] = 8;

      param_1[0x35] = 0;

      param_1[0x36] = 0;

      param_1[0x37] = 0;

    }

    else if (uVar1 == 0x54) {

      param_1[0x34] = 0xd;

      param_1[0x35] = 0;

      param_1[0x36] = 0;

      param_1[0x37] = 0;

    }

    else {

      if (uVar1 == 0x68) {

        if (**(short **)(param_1 + 0x10) == 0x68) {

          *(short **)(param_1 + 0x10) = *(short **)(param_1 + 0x10) + 1;

          psVar6 = (short *)0x1;

        }

        else {

          psVar6 = (short *)0x2;

        }

      }

      else {

        if (uVar1 == 0x6a) {

          param_1[0x34] = 5;

          param_1[0x35] = 0;

          param_1[0x36] = 0;

          param_1[0x37] = 0;

          goto LAB_1402d55aa;

        }

        if (uVar1 != 0x6c) {

          if (uVar1 == 0x74) {

            param_1[0x34] = 7;

            param_1[0x35] = 0;

            param_1[0x36] = 0;

            param_1[0x37] = 0;

          }

          else if (uVar1 == 0x77) {

            param_1[0x34] = 0xc;

            param_1[0x35] = 0;

            param_1[0x36] = 0;

            param_1[0x37] = 0;

          }

          else if (uVar1 == 0x7a) {

            param_1[0x34] = 6;

            param_1[0x35] = 0;

            param_1[0x36] = 0;

            param_1[0x37] = 0;

          }

          goto LAB_1402d55aa;

        }

        if (**(short **)(param_1 + 0x10) == 0x6c) {

          *(short **)(param_1 + 0x10) = *(short **)(param_1 + 0x10) + 1;

          psVar6 = (short *)0x4;

        }

        else {

          psVar6 = (short *)0x3;

        }

      }

      *(int *)(param_1 + 0x34) = (int)psVar6;

    }

  }

LAB_1402d55aa:

  return CONCAT71((int7)((ulonglong)psVar6 >> 8),1);

}




