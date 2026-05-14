// Address: 0x1401c78e0
// Ghidra name: FUN_1401c78e0
// ============ 0x1401c78e0 FUN_1401c78e0 (size=241) ============


undefined4 *

FUN_1401c78e0(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             longlong param_5)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined8 uVar4;

  

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x68);

  if (puVar1 != (undefined4 *)0x0) {

    *puVar1 = param_2;

    puVar1[1] = param_3;

    puVar1[2] = param_4;

    puVar1[8] = 1;

    puVar1[9] = 1;

    lVar2 = FUN_1401841a0(1,8);

    *(longlong *)(puVar1 + 6) = lVar2;

    if (lVar2 != 0) {

      *(undefined8 *)(puVar1 + 0x18) = 0;

      plVar3 = (longlong *)FUN_1401c7580(param_1,param_2,param_3,param_4,param_5);

      if (plVar3 == (longlong *)0x0) {

        FUN_1401841e0();

        FUN_1401841e0(puVar1);

        return (undefined4 *)0x0;

      }

      *(longlong **)(puVar1 + 4) = plVar3;

      **(undefined8 **)(puVar1 + 6) = plVar3;

      *plVar3 = (longlong)puVar1;

      *(undefined4 *)(plVar3 + 1) = 0;

      if (param_5 == 0) {

        return puVar1;

      }

      uVar4 = FUN_14012f0d0(param_5);

      *(undefined8 *)(puVar1 + 0x18) = uVar4;

      return puVar1;

    }

    FUN_1401841e0(puVar1);

  }

  return (undefined4 *)0x0;

}




