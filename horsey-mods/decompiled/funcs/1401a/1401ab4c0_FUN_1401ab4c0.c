// Address: 0x1401ab4c0
// Ghidra name: FUN_1401ab4c0
// ============ 0x1401ab4c0 FUN_1401ab4c0 (size=112) ============


void FUN_1401ab4c0(longlong param_1)



{

  undefined8 *puVar1;

  code *pcVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  

  pcVar2 = *(code **)(param_1 + 0x20);

  if (pcVar2 != (code *)0x0) {

    puVar4 = *(undefined8 **)(param_1 + 8);

    uVar3 = *(undefined8 *)(param_1 + 0x28);

    puVar1 = puVar4 + (ulonglong)(*(int *)(param_1 + 0x30) + 1) * 3;

    for (; puVar4 < puVar1; puVar4 = puVar4 + 3) {

      if ((int)*(uint *)((longlong)puVar4 + 0x14) < 0) {

        *(uint *)((longlong)puVar4 + 0x14) = *(uint *)((longlong)puVar4 + 0x14) & 0x7fffffff;

        (*pcVar2)(uVar3,*puVar4,puVar4[1]);

      }

    }

  }

  return;

}




