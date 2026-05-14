// Address: 0x1401c5560
// Ghidra name: FUN_1401c5560
// ============ 0x1401c5560 FUN_1401c5560 (size=301) ============


undefined8 * FUN_1401c5560(longlong param_1)



{

  int iVar1;

  undefined8 *puVar2;

  HANDLE pvVar3;

  uint uVar4;

  longlong *local_res8;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x220));

  if (*(int *)(param_1 + 0x158) == 0) {

    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x120))();

    if (iVar1 < 0) {

      FUN_1401cb240(param_1,"Failed to create fence!",iVar1);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x220));

      return (undefined8 *)0x0;

    }

    puVar2 = (undefined8 *)FUN_1401841a0(1,0x18);

    if (puVar2 == (undefined8 *)0x0) {

      (**(code **)(*local_res8 + 0x10))();

      FUN_140179b60(*(undefined8 *)(param_1 + 0x220));

      return (undefined8 *)0x0;

    }

    *puVar2 = local_res8;

    pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

    puVar2[1] = pvVar3;

    FUN_140139010(puVar2 + 2,0);

  }

  else {

    uVar4 = *(int *)(param_1 + 0x158) - 1;

    puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0x150) + (ulonglong)uVar4 * 8);

    *(uint *)(param_1 + 0x158) = uVar4;

    (**(code **)(*(longlong *)*puVar2 + 0x50))((longlong *)*puVar2,0);

  }

  FUN_140179b60(*(undefined8 *)(param_1 + 0x220));

  FUN_140138fb0(puVar2 + 2,1);

  return puVar2;

}




