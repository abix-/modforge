// Address: 0x140184590
// Ghidra name: FUN_140184590
// ============ 0x140184590 FUN_140184590 (size=137) ============


undefined4 FUN_140184590(undefined4 *param_1,undefined4 *param_2)



{

  char cVar1;

  undefined **ppuVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  undefined4 local_res18 [2];

  

  local_res8[0] = 0;

  puVar4 = local_res10;

  if (param_1 != (undefined4 *)0x0) {

    puVar4 = param_1;

  }

  ppuVar2 = &PTR_FUN_1403e39a0;

  puVar3 = local_res18;

  if (param_2 != (undefined4 *)0x0) {

    puVar3 = param_2;

  }

  do {

    cVar1 = (*(code *)*ppuVar2)(local_res8,puVar4,puVar3);

    if (cVar1 != '\0') {

      return local_res8[0];

    }

    ppuVar2 = ppuVar2 + 1;

  } while ((longlong)ppuVar2 < 0x1403e39a8);

  *puVar4 = 0xffffffff;

  *puVar3 = 0xffffffff;

  return 0;

}




