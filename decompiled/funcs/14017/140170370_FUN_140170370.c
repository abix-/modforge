// Address: 0x140170370
// Ghidra name: FUN_140170370
// ============ 0x140170370 FUN_140170370 (size=190) ============


void FUN_140170370(undefined4 *param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  char cVar6;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined8 local_18;

  

  if (*(char *)(param_1 + 0x19) == '\0') {

    local_38 = *(undefined8 *)(param_1 + 8);

    uStack_30 = *(undefined8 *)(param_1 + 10);

    puVar1 = (undefined8 *)(param_1 + 8);

    local_28 = param_1[0xc];

    uStack_24 = param_1[0xd];

    uStack_20 = param_1[0xe];

    uStack_1c = param_1[0xf];

    local_18 = *(undefined8 *)(param_1 + 0x10);

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

    uVar5 = param_2[1];

    *puVar1 = *param_2;

    *(undefined8 *)(param_1 + 10) = uVar5;

    uVar2 = *(undefined4 *)((longlong)param_2 + 0x14);

    uVar3 = *(undefined4 *)(param_2 + 3);

    uVar4 = *(undefined4 *)((longlong)param_2 + 0x1c);

    param_1[0xc] = *(undefined4 *)(param_2 + 2);

    param_1[0xd] = uVar2;

    param_1[0xe] = uVar3;

    param_1[0xf] = uVar4;

    *(undefined8 *)(param_1 + 0x10) = param_2[4];

    *(undefined4 *)puVar1 = *param_1;

    FUN_14016bc10(puVar1);

    cVar6 = FUN_140169c20(&local_38,puVar1);

    if ((cVar6 != '\0') &&

       (FUN_14021a690(param_1,0x155,*(undefined4 *)(param_2 + 1),

                      *(undefined4 *)((longlong)param_2 + 0xc)),

       *(undefined8 **)(param_1 + 0x12) == puVar1)) {

      FUN_14021a690(param_1,0x156,*(undefined4 *)(param_2 + 1),

                    *(undefined4 *)((longlong)param_2 + 0xc));

    }

  }

  return;

}




