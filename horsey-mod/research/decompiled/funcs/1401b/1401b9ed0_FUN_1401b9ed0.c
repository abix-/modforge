// Address: 0x1401b9ed0
// Ghidra name: FUN_1401b9ed0
// ============ 0x1401b9ed0 FUN_1401b9ed0 (size=216) ============


undefined8 FUN_1401b9ed0(undefined8 param_1,longlong param_2,uint *param_3)



{

  char cVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar4;

  undefined8 *puVar5;

  uint uVar6;

  longlong lVar7;

  

  puVar5 = *(undefined8 **)(param_2 + 0x240);

  if (*(uint *)(puVar5 + 1) <= *param_3) {

    uVar2 = FUN_140184230(*puVar5,(ulonglong)(*param_3 + 1) << 5);

    *puVar5 = uVar2;

    uVar3 = *param_3;

    uVar6 = *(uint *)(*(longlong *)(param_2 + 0x240) + 8);

    if (uVar6 < uVar3 + 1) {

      do {

        uVar4 = (ulonglong)uVar6;

        uVar6 = uVar6 + 1;

        puVar5 = (undefined8 *)(uVar4 * 0x20 + **(longlong **)(param_2 + 0x240));

        *puVar5 = 0;

        puVar5[1] = 0;

        puVar5[2] = 0;

        puVar5[3] = 0;

        uVar3 = *param_3;

      } while (uVar6 < uVar3 + 1);

    }

    *(uint *)(*(longlong *)(param_2 + 0x240) + 8) = uVar3 + 1;

  }

  lVar7 = **(longlong **)(param_2 + 0x240) + (ulonglong)*param_3 * 0x20;

  if ((*(int *)(lVar7 + 0x1c) == *(int *)(lVar7 + 0x18)) &&

     (cVar1 = FUN_1401b31f0(param_1,param_3,lVar7), cVar1 == '\0')) {

    return 0;

  }

  uVar2 = *(undefined8 *)(*(longlong *)(lVar7 + 0x10) + (ulonglong)*(uint *)(lVar7 + 0x1c) * 8);

  *(uint *)(lVar7 + 0x1c) = *(uint *)(lVar7 + 0x1c) + 1;

  return uVar2;

}




