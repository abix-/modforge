// Address: 0x1402f0a20
// Ghidra name: FUN_1402f0a20
// ============ 0x1402f0a20 FUN_1402f0a20 (size=817) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



ulonglong FUN_1402f0a20(longlong *param_1,undefined8 param_2,uint param_3,char *param_4,int param_5,

                       undefined8 param_6,int param_7,int param_8,int param_9)



{

  longlong lVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  size_t sVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  ulonglong uVar10;

  undefined4 *puVar11;

  undefined1 *puVar12;

  undefined1 *puVar13;

  undefined1 *puVar14;

  undefined1 *puVar15;

  undefined1 auStack_88 [32];

  undefined8 local_68;

  undefined4 local_60;

  undefined4 local_38 [2];

  ulonglong local_30;

  

  puVar12 = auStack_88;

  puVar14 = auStack_88;

  local_30 = DAT_1403e8b00 ^ (ulonglong)local_38;

  iVar2 = param_5;

  if (0 < param_5) {

    sVar5 = __strncnt(param_4,(longlong)param_5);

    iVar4 = (int)sVar5;

    iVar2 = iVar4 + 1;

    if (param_5 <= iVar4) {

      iVar2 = iVar4;

    }

  }

  if (param_8 == 0) {

    param_8 = *(int *)(*param_1 + 0xc);

  }

  local_60 = 0;

  local_68 = 0;

  uVar6 = FUN_1402f3150(param_8,(-(param_9 != 0) & 8U) + 1,param_4,iVar2);

  puVar11 = (undefined4 *)0x0;

  iVar4 = (int)uVar6;

  puVar15 = auStack_88;

  if (iVar4 == 0) goto LAB_1402f0d2b;

  uVar7 = (longlong)iVar4 * 2 + 0x10;

  uVar7 = -(ulonglong)((ulonglong)((longlong)iVar4 * 2) < uVar7) & uVar7;

  if (uVar7 == 0) {

LAB_1402f0d11:

    uVar7 = 0;

    if (puVar11 != (undefined4 *)0x0) goto LAB_1402f0d18;

  }

  else {

    if (uVar7 < 0x401) {

      uVar10 = uVar7 + 0xf;

      if (uVar10 <= uVar7) {

        uVar10 = 0xffffffffffffff0;

      }

      lVar1 = -(uVar10 & 0xfffffffffffffff0);

      puVar14 = auStack_88 + lVar1;

      puVar12 = auStack_88 + lVar1;

      puVar8 = (undefined4 *)((longlong)local_38 + lVar1);

      puVar11 = (undefined4 *)0x0;

      if (puVar8 == (undefined4 *)0x0) goto LAB_1402f0d11;

      *puVar8 = 0xcccc;

LAB_1402f0b2c:

      puVar11 = puVar8 + 4;

      puVar14 = puVar12;

    }

    else {

      puVar8 = (undefined4 *)_malloc_base(uVar7);

      puVar11 = (undefined4 *)0x0;

      puVar14 = auStack_88;

      if (puVar8 != (undefined4 *)0x0) {

        *puVar8 = 0xdddd;

        goto LAB_1402f0b2c;

      }

    }

    if (puVar11 == (undefined4 *)0x0) goto LAB_1402f0d11;

    *(int *)(puVar14 + 0x28) = iVar4;

    *(undefined4 **)(puVar14 + 0x20) = puVar11;

    *(undefined8 *)(puVar14 + -8) = 0x1402f0b56;

    iVar2 = FUN_1402f3150(param_8,1,param_4,iVar2);

    if (iVar2 == 0) goto LAB_1402f0d11;

    *(undefined8 *)(puVar14 + 0x40) = 0;

    *(undefined8 *)(puVar14 + 0x38) = 0;

    *(undefined8 *)(puVar14 + 0x30) = 0;

    *(undefined4 *)(puVar14 + 0x28) = 0;

    *(undefined8 *)(puVar14 + 0x20) = 0;

    *(undefined8 *)(puVar14 + -8) = 0x1402f0b89;

    iVar2 = FUN_1402ec3cc(param_2,param_3,puVar11,uVar6 & 0xffffffff);

    puVar8 = (undefined4 *)0x0;

    uVar7 = (ulonglong)iVar2;

    if (iVar2 == 0) goto LAB_1402f0d11;

    if ((param_3 & 0x400) == 0) {

      uVar10 = uVar7 * 2 + 0x10;

      uVar10 = -(ulonglong)(uVar7 * 2 < uVar10) & uVar10;

      if (uVar10 == 0) goto LAB_1402f0cf4;

      if (uVar10 < 0x401) {

        uVar7 = uVar10 + 0xf;

        if (uVar7 <= uVar10) {

          uVar7 = 0xffffffffffffff0;

        }

        *(undefined8 *)(puVar14 + -8) = 0x1402f0c2c;

        lVar1 = -(uVar7 & 0xfffffffffffffff0);

        puVar13 = puVar14 + lVar1;

        puVar9 = (undefined4 *)(puVar14 + lVar1 + 0x50);

        puVar14 = puVar14 + lVar1;

        if (puVar9 != (undefined4 *)0x0) {

          *puVar9 = 0xcccc;

          puVar14 = puVar13;

LAB_1402f0c5a:

          puVar8 = puVar9 + 4;

          goto LAB_1402f0c5e;

        }

      }

      else {

        *(undefined8 *)(puVar14 + -8) = 0x1402f0c4a;

        puVar9 = (undefined4 *)_malloc_base();

        puVar8 = (undefined4 *)0x0;

        if (puVar9 != (undefined4 *)0x0) {

          *puVar9 = 0xdddd;

          goto LAB_1402f0c5a;

        }

LAB_1402f0c5e:

        if (puVar8 != (undefined4 *)0x0) {

          *(undefined8 *)(puVar14 + 0x40) = 0;

          *(undefined8 *)(puVar14 + 0x38) = 0;

          *(undefined8 *)(puVar14 + 0x30) = 0;

          *(int *)(puVar14 + 0x28) = iVar2;

          *(undefined4 **)(puVar14 + 0x20) = puVar8;

          *(undefined8 *)(puVar14 + -8) = 0x1402f0c90;

          iVar4 = FUN_1402ec3cc(param_2,param_3,puVar11,uVar6 & 0xffffffff);

          if (iVar4 != 0) {

            *(undefined8 *)(puVar14 + 0x38) = 0;

            *(undefined8 *)(puVar14 + 0x30) = 0;

            if (param_7 == 0) {

              *(undefined4 *)(puVar14 + 0x28) = 0;

              *(undefined8 *)(puVar14 + 0x20) = 0;

              *(undefined8 *)(puVar14 + -8) = 0x1402f0cbe;

              uVar3 = FUN_1402f31e0(param_8,0,puVar8,iVar2);

              if (uVar3 == 0) goto LAB_1402f0cf4;

            }

            else {

              *(int *)(puVar14 + 0x28) = param_7;

              *(undefined8 *)(puVar14 + 0x20) = param_6;

              *(undefined8 *)(puVar14 + -8) = 0x1402f0cd8;

              uVar3 = FUN_1402f31e0(param_8,0,puVar8,iVar2);

              if (uVar3 == 0) goto LAB_1402f0cf9;

            }

            uVar7 = (ulonglong)uVar3;

            if (puVar8[-4] == 0xdddd) {

              *(undefined8 *)(puVar14 + -8) = 0x1402f0cef;

              FUN_1402e9a80();

            }

            goto LAB_1402f0d18;

          }

LAB_1402f0cf4:

          if (puVar8 != (undefined4 *)0x0) {

LAB_1402f0cf9:

            if (puVar8[-4] == 0xdddd) {

              *(undefined8 *)(puVar14 + -8) = 0x1402f0d0a;

              FUN_1402e9a80();

            }

          }

        }

      }

      uVar7 = 0;

    }

    else if (param_7 != 0) {

      if (iVar2 <= param_7) {

        *(undefined8 *)(puVar14 + 0x40) = 0;

        *(undefined8 *)(puVar14 + 0x38) = 0;

        *(undefined8 *)(puVar14 + 0x30) = 0;

        *(int *)(puVar14 + 0x28) = param_7;

        *(undefined8 *)(puVar14 + 0x20) = param_6;

        *(undefined8 *)(puVar14 + -8) = 0x1402f0be1;

        uVar3 = FUN_1402ec3cc(param_2,param_3,puVar11,uVar6 & 0xffffffff);

        uVar7 = (ulonglong)uVar3;

        if (uVar3 != 0) goto LAB_1402f0d18;

      }

      goto LAB_1402f0d11;

    }

LAB_1402f0d18:

    if (puVar11[-4] == 0xdddd) {

      *(undefined8 *)(puVar14 + -8) = 0x1402f0d29;

      FUN_1402e9a80();

    }

  }

  uVar6 = uVar7 & 0xffffffff;

  puVar15 = puVar14;

LAB_1402f0d2b:

  *(undefined8 *)(puVar15 + -8) = 0x1402f0d37;

  return uVar6;

}




