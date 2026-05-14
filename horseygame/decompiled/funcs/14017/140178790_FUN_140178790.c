// Address: 0x140178790
// Ghidra name: FUN_140178790
// ============ 0x140178790 FUN_140178790 (size=340) ============


longlong FUN_140178790(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  size_t sVar4;

  longlong lVar5;

  char *_Str;

  longlong lVar6;

  char local_res8 [8];

  longlong local_res20;

  int local_48 [12];

  

  lVar6 = 0;

  local_res20 = 0;

  iVar2 = FUN_14012ee40(&local_res20,&DAT_14031bb40,param_2,param_3);

  if (iVar2 < 0) {

    return 2;

  }

  lVar3 = lVar6;

  if (((*(byte *)((longlong)param_1 + 0x14) & 1) != 0) &&

     (lVar3 = FUN_1401785d0(local_res20), lVar3 == 0)) {

    return 2;

  }

  lVar5 = local_res20;

  if (lVar3 != 0) {

    lVar5 = lVar3;

  }

  local_res8[0] = '\0';

  cVar1 = (*(code *)*param_1)(param_1[1],lVar5 + param_1[6],local_res8);

  FUN_1401841e0(lVar3);

  if (cVar1 != '\0') {

    _Str = (char *)(local_res20 + param_1[6]);

    sVar4 = strlen(_Str);

    lVar3 = FUN_14012cbb0(param_1[7],_Str,sVar4 + 1);

    if (lVar3 != sVar4 + 1) {

      FUN_1401841e0(local_res20);

      return 2;

    }

    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;

  }

  if (((local_res8[0] != '\0') &&

      (cVar1 = (*(code *)param_1[4])(local_res20,local_48,param_1[5]), cVar1 != '\0')) &&

     (local_48[0] == 2)) {

    cVar1 = (*(code *)param_1[3])(local_res20,FUN_140178790,param_1,param_1[5]);

    lVar6 = 0;

    if (cVar1 == '\0') {

      lVar6 = 2;

    }

  }

  FUN_1401841e0(local_res20);

  return lVar6;

}




