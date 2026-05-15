// Address: 0x1401fd130
// Ghidra name: FUN_1401fd130
// ============ 0x1401fd130 FUN_1401fd130 (size=228) ============


undefined1

FUN_1401fd130(longlong param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4,

             undefined4 *param_5)



{

  int iVar1;

  longlong lVar2;

  undefined1 uVar3;

  int iVar4;

  longlong lVar5;

  undefined8 *puVar6;

  undefined8 uVar7;

  

  lVar2 = *(longlong *)(param_2 + 0x138);

  uVar7 = *(undefined8 *)(param_1 + 0x2e0);

  if (lVar2 == 0) {

    uVar3 = FUN_14012e850("Texture is not currently available");

    return uVar3;

  }

  if (*(longlong *)(lVar2 + 0x48) == 0) {

    puVar6 = param_3;

    lVar5 = FUN_1401fa4f0(*(undefined4 *)(lVar2 + 0x24),0);

    iVar1 = *(int *)(puVar6 + 1);

    iVar4 = FUN_1401f58a0(uVar7,(longlong)*(int *)((longlong)param_3 + 0xc) * lVar5 * iVar1,1,6,1,

                          lVar2 + 0x40);

    if (iVar4 == 0) {

      uVar7 = param_3[1];

      *(undefined8 *)(lVar2 + 0x60) = *param_3;

      *(undefined8 *)(lVar2 + 0x68) = uVar7;

      *param_4 = *(undefined8 *)(lVar2 + 0x58);

      *param_5 = (int)(lVar5 * iVar1);

    }

    return iVar4 == 0;

  }

  uVar3 = FUN_14012e850("texture is already locked");

  return uVar3;

}




