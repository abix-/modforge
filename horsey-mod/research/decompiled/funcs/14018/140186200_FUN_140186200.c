// Address: 0x140186200
// Ghidra name: FUN_140186200
// ============ 0x140186200 FUN_140186200 (size=54) ============


ulonglong FUN_140186200(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  

  uVar2 = 0;

  if (0 < *(int *)(param_1 + 0xc)) {

    puVar1 = *(undefined8 **)(param_1 + 0x18);

    uVar3 = uVar2;

    do {

      if (*(longlong *)*puVar1 == param_2) {

        return uVar3;

      }

      uVar3 = (ulonglong)((int)uVar3 + 1);

      uVar2 = uVar2 + 1;

      puVar1 = puVar1 + 1;

    } while ((longlong)uVar2 < (longlong)*(int *)(param_1 + 0xc));

  }

  return 0xffffffff;

}




