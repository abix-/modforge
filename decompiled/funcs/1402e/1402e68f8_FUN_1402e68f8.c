// Address: 0x1402e68f8
// Ghidra name: FUN_1402e68f8
// ============ 0x1402e68f8 FUN_1402e68f8 (size=413) ============


uint FUN_1402e68f8(char *param_1,longlong param_2,undefined8 param_3,undefined4 param_4)



{

  int iVar1;

  DWORD DVar2;

  longlong lVar3;

  uint *puVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  bool bVar8;

  

  if (param_1 == (char *)0x0) {

    if (*(char *)(param_2 + 0x28) != '\0') {

      FUN_1402e9a80(*(undefined8 *)(param_2 + 0x10));

      *(undefined1 *)(param_2 + 0x28) = 0;

    }

    *(undefined8 *)(param_2 + 0x10) = 0;

    *(undefined8 *)(param_2 + 0x18) = 0;

  }

  else {

    if (*param_1 != '\0') {

      iVar1 = FUN_1402f3150(param_4,9,param_1,0xffffffff,0,0);

      uVar7 = (ulonglong)iVar1;

      if (iVar1 != 0) {

        uVar6 = *(ulonglong *)(param_2 + 0x18);

        if (uVar6 < uVar7) {

          if (*(char *)(param_2 + 0x28) != '\0') {

            FUN_1402e9a80(*(undefined8 *)(param_2 + 0x10));

            *(undefined1 *)(param_2 + 0x28) = 0;

          }

          lVar3 = _malloc_base(uVar7 * 2);

          *(longlong *)(param_2 + 0x10) = lVar3;

          uVar6 = -(ulonglong)(lVar3 != 0) & uVar7;

          uVar5 = ~-(uint)(lVar3 != 0) & 0xc;

          if (lVar3 != 0) {

            uVar5 = 0;

          }

          *(bool *)(param_2 + 0x28) = lVar3 != 0;

          *(ulonglong *)(param_2 + 0x18) = uVar6;

          if (uVar5 != 0) {

            return uVar5;

          }

        }

        iVar1 = FUN_1402f3150(param_4,9,param_1,0xffffffff,*(undefined8 *)(param_2 + 0x10),

                              (int)uVar6);

        if ((longlong)iVar1 != 0) {

          *(longlong *)(param_2 + 0x20) = (longlong)iVar1 + -1;

          return 0;

        }

      }

      DVar2 = GetLastError();

      FUN_1402e6840(DVar2);

      puVar4 = (uint *)FUN_1402e68b0();

      return *puVar4;

    }

    if (*(longlong *)(param_2 + 0x18) == 0) {

      if (*(char *)(param_2 + 0x28) != '\0') {

        FUN_1402e9a80(*(undefined8 *)(param_2 + 0x10));

        *(undefined1 *)(param_2 + 0x28) = 0;

      }

      lVar3 = _malloc_base(2);

      *(longlong *)(param_2 + 0x10) = lVar3;

      bVar8 = lVar3 != 0;

      uVar5 = ~-(uint)(lVar3 != 0) & 0xc;

      if (bVar8) {

        uVar5 = 0;

      }

      *(bool *)(param_2 + 0x28) = bVar8;

      *(ulonglong *)(param_2 + 0x18) = (ulonglong)bVar8;

      if (uVar5 != 0) {

        return uVar5;

      }

    }

    **(undefined2 **)(param_2 + 0x10) = 0;

  }

  *(undefined8 *)(param_2 + 0x20) = 0;

  return 0;

}




