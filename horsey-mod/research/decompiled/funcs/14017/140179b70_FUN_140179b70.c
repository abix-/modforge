// Address: 0x140179b70
// Ghidra name: FUN_140179b70
// ============ 0x140179b70 FUN_140179b70 (size=175) ============


undefined1 * FUN_140179b70(int *param_1,undefined8 param_2,undefined4 *param_3)



{

  char cVar1;

  undefined1 uVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined1 *puVar8;

  

  cVar1 = FUN_14017bac0();

  if (cVar1 == '\0') {

    uVar6 = 0;

    *param_3 = 0;

    puVar3 = (undefined1 *)FUN_1401841a0(0x100,1);

    if ((puVar3 != (undefined1 *)0x0) && (uVar7 = uVar6, puVar8 = puVar3, 0 < *param_1)) {

      do {

        puVar4 = (undefined1 *)(*(longlong *)(param_1 + 2) + uVar7);

        uVar2 = FUN_14017a230(param_2,*puVar4,puVar4[1],puVar4[2],puVar4[3]);

        *puVar8 = uVar2;

        uVar5 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar5;

        uVar7 = uVar7 + 4;

        puVar8 = puVar8 + 1;

      } while ((int)uVar5 < *param_1);

    }

    return puVar3;

  }

  *param_3 = 1;

  return (undefined1 *)0x0;

}




