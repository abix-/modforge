// Address: 0x1402c5930
// Ghidra name: FUN_1402c5930
// ============ 0x1402c5930 FUN_1402c5930 (size=89) ============


undefined4 * FUN_1402c5930(undefined8 param_1,undefined4 param_2)



{

  char cVar1;

  undefined4 *puVar2;

  undefined1 local_58 [52];

  undefined4 local_24;

  undefined8 local_18;

  

  puVar2 = (undefined4 *)0x0;

  cVar1 = FUN_1402c55b0(local_58,param_1,param_2);

  if (cVar1 != '\0') {

    puVar2 = (undefined4 *)FUN_1401841f0(0x10);

    if (puVar2 != (undefined4 *)0x0) {

      *puVar2 = local_24;

      *(undefined8 *)(puVar2 + 2) = local_18;

      local_18 = 0;

    }

  }

  FUN_1402c5590(local_58);

  return puVar2;

}




