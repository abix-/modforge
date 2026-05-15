// Address: 0x140182c80
// Ghidra name: FUN_140182c80
// ============ 0x140182c80 FUN_140182c80 (size=174) ============


void FUN_140182c80(undefined8 *param_1,ulonglong param_2,ulonglong param_3,int param_4)



{

  char cVar1;

  ushort uVar2;

  ulonglong uVar3;

  undefined4 local_res8;

  

  if (param_1 != (undefined8 *)0x0) {

    uVar3 = param_2 & 0xffffffff;

    uVar2 = FUN_1401818e0(param_3 & 0xffff,param_2,param_3,uVar3);

    uVar3 = (ulonglong)uVar2 << 0x10 | uVar3;

    cVar1 = FUN_1401aaff0(*param_1,uVar3,&local_res8);

    if ((cVar1 == '\0') || (local_res8 != param_4)) {

      FUN_1401ab100(*param_1,uVar3,param_4,1);

      cVar1 = FUN_1401aaff0(param_1[1],param_4,&local_res8);

      if ((cVar1 == '\0') || (uVar2 < local_res8._2_2_)) {

        FUN_1401ab100(param_1[1],param_4,uVar3,1);

      }

    }

  }

  return;

}




