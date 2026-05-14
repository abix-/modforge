// Address: 0x1401acb50
// Ghidra name: FUN_1401acb50
// ============ 0x1401acb50 FUN_1401acb50 (size=249) ============


void FUN_1401acb50(longlong *param_1)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong *local_res10;

  undefined8 local_18;

  int local_10;

  

  lVar2 = FUN_1401acd10(param_1,&DAT_14033cbd0);

  lVar3 = FUN_140131840(FUN_1401abb10,lVar2);

  lVar4 = lVar2;

  if (((lVar3 == 0) && (lVar4 = FUN_1401acd10(param_1,&DAT_14033cbb0), lVar4 != 0)) && (lVar2 != 0))

  {

    local_res10 = (longlong *)0x0;

    iVar1 = (**(code **)(*param_1 + 0x108))(param_1,&DAT_14033cad0,&local_res10);

    if ((-1 < iVar1) && (local_res10 != (longlong *)0x0)) {

      FUN_1401abb30(local_res10,&local_18);

      if (0 < local_10) {

        FUN_140130c90(lVar4,0,local_10,local_18,lVar2);

      }

      FUN_1401841e0(local_18);

      (**(code **)(*param_1 + 0x110))(param_1);

      (**(code **)(*local_res10 + 0x10))();

    }

  }

  FUN_1401841e0(lVar4);

  return;

}




