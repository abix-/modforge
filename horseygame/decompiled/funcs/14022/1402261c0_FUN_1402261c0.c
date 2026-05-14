// Address: 0x1402261c0
// Ghidra name: FUN_1402261c0
// ============ 0x1402261c0 FUN_1402261c0 (size=286) ============


longlong * FUN_1402261c0(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  longlong *plVar4;

  longlong *plVar5;

  int iVar6;

  longlong *local_res8;

  longlong *local_res18;

  undefined1 local_78 [96];

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  plVar4 = (longlong *)0x0;

  if (*(longlong *)(lVar1 + 0xf0) == 0) {

    return (longlong *)0x0;

  }

  iVar6 = 0;

  do {

    plVar5 = *(longlong **)(lVar1 + 0xf0);

    iVar2 = (**(code **)(*plVar5 + 0x38))(plVar5,iVar6,&local_res18);

    if (iVar2 < 0) {

      return plVar4;

    }

    iVar2 = 0;

    while ((plVar4 == (longlong *)0x0 &&

           (iVar3 = (**(code **)(*local_res18 + 0x38))(local_res18,iVar2,&local_res8), -1 < iVar3)))

    {

      iVar3 = (**(code **)(*local_res8 + 0x38))(local_res8,local_78);

      if (((iVar3 < 0) || (iVar3 = FUN_14012fbc0(local_78,param_2), plVar5 = local_res8, iVar3 != 0)

          ) && (plVar5 = plVar4, local_res8 != (longlong *)0x0)) {

        (**(code **)(*local_res8 + 0x10))();

      }

      iVar2 = iVar2 + 1;

      plVar4 = plVar5;

    }

    (**(code **)(*local_res18 + 0x10))();

    iVar6 = iVar6 + 1;

  } while (plVar4 == (longlong *)0x0);

  return plVar4;

}




