// Address: 0x1402d1648
// Ghidra name: FUN_1402d1648
// ============ 0x1402d1648 FUN_1402d1648 (size=529) ============


ulonglong FUN_1402d1648(char *param_1,ulonglong param_2,ulonglong param_3,FILE *param_4,

                       longlong param_5)



{

  uint *puVar1;

  undefined1 auVar2 [16];

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  uint uVar8;

  uint uVar9;

  

  if ((param_2 != 0) && (param_3 != 0)) {

    if ((param_4 != (FILE *)0x0) &&

       ((param_1 != (char *)0x0 &&

        (auVar2._8_8_ = 0, auVar2._0_8_ = param_2,

        param_3 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0))))) {

      if (((ulonglong)param_4->_base & 0x4c000000000) == 0) {

        uVar9 = 0x1000;

      }

      else {

        uVar9 = param_4->_charbuf;

      }

      uVar7 = param_2 * param_3;

      do {

        if (uVar7 == 0) {

          return param_3;

        }

        if ((((ulonglong)param_4->_base & 0xc000000000) == 0) || (*(int *)&param_4->_base == 0)) {

          if (uVar9 <= uVar7) {

            if ((((ulonglong)param_4->_base & 0xc000000000) != 0) &&

               (iVar3 = FUN_1402e1948(param_4), iVar3 != 0)) goto LAB_1402d17ff;

            uVar5 = uVar7;

            if (uVar9 != 0) {

              uVar5 = uVar7 - uVar7 % (ulonglong)uVar9;

            }

            uVar8 = 0xfffffffe;

            if (uVar5 < 0xfffffffe) {

              uVar8 = (uint)uVar5;

            }

            iVar3 = _fileno(param_4);

            uVar4 = FUN_1402ee50c(iVar3,param_1,uVar8,param_5);

            if (uVar4 != 0xffffffff) {

              uVar6 = uVar4;

              if (uVar8 < uVar4) {

                uVar6 = uVar8;

              }

              uVar5 = (ulonglong)uVar6;

              uVar7 = uVar7 - uVar5;

              if (uVar8 <= uVar4) goto LAB_1402d1846;

            }

LAB_1402d17fa:

            LOCK();

            puVar1 = (uint *)((longlong)&param_4->_base + 4);

            *puVar1 = *puVar1 | 0x10;

            UNLOCK();

LAB_1402d17ff:

            return (param_2 * param_3 - uVar7) / param_2;

          }

          iVar3 = FUN_1402eebd8((int)*param_1,param_4,param_5);

          if (iVar3 == -1) goto LAB_1402d17ff;

          uVar9 = param_4->_charbuf;

          uVar7 = uVar7 - 1;

          if ((int)uVar9 < 1) {

            uVar9 = 1;

            uVar5 = 1;

          }

          else {

            uVar5 = 1;

          }

        }

        else {

          if (*(int *)&param_4->_base < 0) goto LAB_1402d17fa;

          if (((ulonglong)param_4->_base & 0x100000000) != 0) goto LAB_1402d17ff;

          uVar5 = uVar7;

          if ((ulonglong)(longlong)*(int *)&param_4->_base <= uVar7) {

            uVar5 = (longlong)*(int *)&param_4->_base;

          }

          FUN_1402f8e20(param_4->_ptr,param_1,uVar5);

          *(int *)&param_4->_base = *(int *)&param_4->_base - (int)uVar5;

          uVar7 = uVar7 - uVar5;

          param_4->_ptr = param_4->_ptr + uVar5;

        }

LAB_1402d1846:

        param_1 = param_1 + uVar5;

      } while( true );

    }

    *(undefined1 *)(param_5 + 0x30) = 1;

    *(undefined4 *)(param_5 + 0x2c) = 0x16;

    FUN_1402cd39c(0,0,0,0,0,param_5);

  }

  return 0;

}




