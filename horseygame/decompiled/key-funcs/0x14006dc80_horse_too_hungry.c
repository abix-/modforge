// Hint: horse_too_hungry
// Address: 0x14006dc80
// Ghidra name: FUN_14006dc80
// ============ 0x14006dc80 FUN_14006dc80 (size=2026) ============


/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14006dc80(longlong param_1,undefined4 param_2)



{

  int iVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  undefined4 *puVar6;

  uint uVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong *******pppppppuVar10;

  ulonglong uVar11;

  undefined8 local_88;

  ulonglong ******ppppppuStack_80;

  ulonglong local_78;

  ulonglong local_70;

  ulonglong *******local_68 [2];

  ulonglong local_58;

  ulonglong local_50;

  undefined1 local_48;

  undefined7 uStack_47;

  undefined8 local_38;

  ulonglong uStack_30;

  

  FUN_1400c4320("_saving_");

  iVar1 = *(int *)(param_1 + 0x25c);

  if (iVar1 == 0x1c) {

    if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x438) + 0xe0) + 0x260) == 0) {

      return;

    }

  }

  else if (iVar1 == -1) goto LAB_14006dd20;

  if ((*(char *)(*(longlong *)(param_1 + 0x300) + 0xac) == '\0') && (iVar1 != 0xd)) {

    FUN_14003f330(1);

    FUN_1400d6a40(*(undefined8 *)

                   (*(longlong *)(param_1 + 0x438) + (longlong)*(int *)(param_1 + 0x25c) * 8));

    FUN_14003f330(0);

  }

LAB_14006dd20:

  if ((*(int *)(param_1 + 0x25c) == 0xd) &&

     (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x70), lVar8 != 0)) {

    FUN_140060710(lVar8,1);

  }

  FUN_14008d760(&local_48,"save%d.dat",param_2);

  uVar2 = FUN_1400c4df0();

  FUN_14006f590(local_68,uVar2);

  if (0xf < uStack_30) {

    if ((0xfff < uStack_30 + 1) &&

       (0x1f < (CONCAT71(uStack_47,local_48) - *(longlong *)(CONCAT71(uStack_47,local_48) + -8)) -

               8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  local_38 = _DAT_14039caa0;

  uStack_30 = _UNK_14039caa8;

  local_48 = 0;

  uVar9 = 0;

  DAT_1403eac50 = 0;

  if ((*(int *)(param_1 + 0x25c) == -1) || (*(int *)(param_1 + 0x25c) != DAT_1403d94b8)) {

    local_88 = (ulonglong ******)0x0;

    ppppppuStack_80 = (ulonglong ******)0x0;

    local_78 = 0;

    local_70 = 0;

    pppppppuVar10 = (ulonglong *******)local_68;

    if (0xf < local_50) {

      pppppppuVar10 = local_68[0];

    }

    if (0x7fffffffffffffff < local_58) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    if (local_58 < 0x10) {

      local_78 = local_58;

      local_70 = 0xf;

      local_88 = *pppppppuVar10;

      ppppppuStack_80 = pppppppuVar10[1];

    }

    else {

      uVar3 = local_58 | 0xf;

      uVar5 = 0x7fffffffffffffff;

      if ((uVar3 < 0x8000000000000000) && (uVar5 = uVar3, uVar3 < 0x16)) {

        uVar5 = 0x16;

      }

      local_88 = (ulonglong ******)FUN_1400285e0(uVar5 + 1);

      local_78 = local_58;

      local_70 = uVar5;

      FUN_1402f8e20(local_88,pppppppuVar10,local_58 + 1);

    }

    FUN_1400c4e20(&local_88);

    DAT_1403d94b8 = *(int *)(param_1 + 0x25c);

  }

  FUN_1400755a0(250000);

  FUN_140075670(0xc);

  FUN_1400c7d80();

  FUN_140075650();

  FUN_140075670(*(undefined4 *)(param_1 + 0x254));

  FUN_140075670(*(undefined4 *)(param_1 + 0x314));

  FUN_140075670(*(undefined4 *)(param_1 + 0x268));

  FUN_140075770();

  FUN_140075670(*(undefined4 *)(param_1 + 0x318));

  FUN_140075670(*(undefined4 *)(param_1 + 0x308));

  FUN_140075670(*(undefined4 *)(param_1 + 0x440));

  FUN_140075750(*(undefined1 *)(param_1 + 0x414));

  FUN_140075750(*(undefined1 *)(param_1 + 0x415));

  FUN_140075670(*(undefined4 *)(param_1 + 0x37c));

  FUN_140075750(0);

  FUN_140075670(*(undefined4 *)(param_1 + 0x418));

  FUN_140075750(*(undefined1 *)(param_1 + 0x41c));

  FUN_140075790(*(undefined8 *)(param_1 + 0x39c));

  FUN_140075670(*(undefined4 *)(param_1 + 0x410));

  puVar6 = (undefined4 *)(param_1 + 0x31c);

  lVar8 = 6;

  do {

    FUN_140075750(*(undefined1 *)((longlong)puVar6 + 5));

    FUN_140075670(*puVar6);

    FUN_140075750(*(undefined1 *)(puVar6 + 1));

    puVar6 = puVar6 + 2;

    lVar8 = lVar8 + -1;

  } while (lVar8 != 0);

  puVar6 = (undefined4 *)(param_1 + 0x2cc);

  lVar8 = 0xd;

  do {

    FUN_140075670(puVar6[-0xd]);

    FUN_140075670(*puVar6);

    puVar6 = puVar6 + 1;

    lVar8 = lVar8 + -1;

  } while (lVar8 != 0);

  FUN_140075650();

  FUN_140075730((*(longlong *)(param_1 + 0x288) - *(longlong *)(param_1 + 0x280)) / 0x24);

  lVar8 = *(longlong *)(param_1 + 0x280);

  uVar5 = uVar9;

  uVar3 = uVar9;

  if ((*(longlong *)(param_1 + 0x288) - lVar8) / 0x24 != 0) {

    do {

      FUN_1400756b0(*(undefined2 *)(lVar8 + 4 + uVar5));

      FUN_1400756b0(*(undefined2 *)(*(longlong *)(param_1 + 0x280) + 8 + uVar5));

      FUN_1400756b0(*(undefined2 *)(*(longlong *)(param_1 + 0x280) + 0xc + uVar5));

      FUN_1400756b0(*(undefined2 *)(*(longlong *)(param_1 + 0x280) + 0x10 + uVar5));

      uVar7 = (int)uVar3 + 1;

      lVar8 = *(longlong *)(param_1 + 0x280);

      uVar5 = uVar5 + 0x24;

      uVar3 = (ulonglong)uVar7;

    } while ((ulonglong)(longlong)(int)uVar7 <

             (ulonglong)((*(longlong *)(param_1 + 0x288) - lVar8) / 0x24));

  }

  FUN_140075670(*(int *)(param_1 + 0x278));

  FUN_140075670(*(int *)(param_1 + 0x27c));

  FUN_140075650();

  lVar8 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar8 + 4) < DAT_1403eacb4) && (FUN_1402c7138(&DAT_1403eacb4), DAT_1403eacb4 == -1))

  {

    ppppppuStack_80 = (ulonglong ******)0x0;

    local_78 = 5;

    local_70 = 0xf;

    local_88._0_5_ = CONCAT14(s_Water_14030a274[4],s_Water_14030a274._0_4_);

    local_88 = (ulonglong ******)(ulonglong)(uint5)local_88;

    DAT_1403eacb0 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403eacb4);

  }

  if ((*(int *)(lVar8 + 4) < DAT_1403eacbc) && (FUN_1402c7138(&DAT_1403eacbc), DAT_1403eacbc == -1))

  {

    ppppppuStack_80 = (ulonglong ******)0x0;

    local_78 = 5;

    local_70 = 0xf;

    local_88._0_5_ = CONCAT14(s_Plain_14030a27c[4],s_Plain_14030a27c._0_4_);

    local_88 = (ulonglong ******)(ulonglong)(uint5)local_88;

    DAT_1403eacb8 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403eacbc);

  }

  uVar5 = uVar9;

  uVar3 = uVar9;

  uVar11 = uVar9;

  if (0 < *(int *)(param_1 + 0x27c) * *(int *)(param_1 + 0x278)) {

    do {

      lVar8 = *(longlong *)(param_1 + 0x270);

      iVar1 = (int)uVar11;

      if ((((*(int *)(lVar8 + uVar5) == 6) && (*(char *)(lVar8 + 0xd + uVar5) == '\0')) &&

          (*(char *)(lVar8 + 0xc + uVar5) == '\0')) &&

         ((*(int *)(lVar8 + 8 + uVar5) == DAT_1403eacb0 && (iVar1 < 0xff)))) {

        uVar11 = (ulonglong)(iVar1 + 1);

      }

      else {

        if (0 < iVar1) {

          FUN_140075710(CONCAT71((int7)((ulonglong)(param_1 + 0x278) >> 8),0x3f));

          FUN_140075710(uVar11 & 0xff);

          uVar11 = uVar9;

        }

        uVar7 = *(uint *)(lVar8 + uVar5);

        if (((uVar7 == 0) && (*(char *)(lVar8 + 0xd + uVar5) == '\0')) &&

           ((*(char *)(lVar8 + 0xc + uVar5) == '\0' &&

            ((iVar1 = *(int *)(lVar8 + 8 + uVar5), DAT_1403eacb8 <= iVar1 &&

             (iVar1 < DAT_1403eacb8 + 4)))))) {

          uVar7 = CONCAT31((int3)((uint)iVar1 >> 8),((char)iVar1 - (char)DAT_1403eacb8) + ';');

        }

        else {

          uVar4 = (uint)(byte)((byte)uVar7 | 0x40);

          if (*(char *)(lVar8 + 0xc + uVar5) == '\0') {

            uVar4 = uVar7 & 0xff;

          }

          uVar7 = (uint)(byte)((byte)uVar4 | 0x80);

          if (*(char *)(lVar8 + 0xd + uVar5) == '\0') {

            uVar7 = uVar4;

          }

          FUN_140075710(uVar7);

          FUN_140075710(*(undefined1 *)(lVar8 + 8 + uVar5));

          iVar1 = FUN_140110750(*(undefined4 *)(lVar8 + uVar5));

          if (iVar1 < 1) goto LAB_14006e1d5;

          uVar7 = (uint)*(byte *)(lVar8 + 4 + uVar5);

        }

        FUN_140075710(uVar7);

      }

LAB_14006e1d5:

      uVar7 = (int)uVar3 + 1;

      uVar5 = uVar5 + 0x28;

      uVar3 = (ulonglong)uVar7;

    } while ((int)uVar7 < *(int *)(param_1 + 0x278) * *(int *)(param_1 + 0x27c));

    if (0 < (int)uVar11) {

      FUN_140075710(CONCAT71((int7)((ulonglong)(param_1 + 0x278) >> 8),0x3f));

      FUN_140075710(uVar11 & 0xff);

    }

  }

  FUN_140075730(*(longlong *)(param_1 + 0x428) - *(longlong *)(param_1 + 0x420) >> 3);

  lVar8 = *(longlong *)(param_1 + 0x420);

  uVar5 = uVar9;

  uVar3 = uVar9;

  if (*(longlong *)(param_1 + 0x428) - lVar8 >> 3 != 0) {

    do {

      FUN_140075670(*(undefined4 *)(lVar8 + uVar5));

      FUN_140075670(*(undefined4 *)(uVar5 + 4 + *(longlong *)(param_1 + 0x420)));

      uVar7 = (int)uVar3 + 1;

      lVar8 = *(longlong *)(param_1 + 0x420);

      uVar5 = uVar5 + 8;

      uVar3 = (ulonglong)uVar7;

    } while ((ulonglong)(longlong)(int)uVar7 <

             (ulonglong)(*(longlong *)(param_1 + 0x428) - lVar8 >> 3));

  }

  FUN_14006d610(param_1);

  do {

    lVar8 = *(longlong *)(uVar9 + *(longlong *)(param_1 + 0x438));

    FUN_140075750(lVar8 != 0);

    if (lVar8 != 0) {

      FUN_14006d610(*(undefined8 *)(uVar9 + *(longlong *)(param_1 + 0x438)));

      (**(code **)(**(longlong **)(uVar9 + *(longlong *)(param_1 + 0x438)) + 0xb0))();

    }

    uVar9 = uVar9 + 8;

  } while ((longlong)uVar9 < 0x180);

  FUN_14006d610(DAT_1403f4e00);

  (**(code **)(*DAT_1403f4e00 + 0xb0))();

  FUN_1400755f0(local_68);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) &&

       (0x1f < (ulonglong)((longlong)local_68[0] + (-8 - (longlong)local_68[0][-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




