// Address: 0x14010f600
// Ghidra name: FUN_14010f600
// ============ 0x14010f600 FUN_14010f600 (size=463) ============


void FUN_14010f600(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  longlong *plVar1;

  float fVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  float fVar6;

  undefined1 local_res8 [8];

  

  FUN_140072860(0);

  fVar2 = DAT_140303fb4;

  lVar5 = *(longlong *)(param_1 + 0xb8);

  iVar3 = 0;

  if (*(longlong *)(param_1 + 0xc0) - lVar5 >> 3 != 0) {

    lVar4 = 0;

    do {

      plVar1 = *(longlong **)(lVar4 + lVar5);

      if ((((*(char *)((longlong)plVar1 + 0x11) == '\0') && ((int)plVar1[1] == 0)) &&

          (fVar6 = *(float *)(plVar1 + 5) * fVar2, (float)param_2 <= fVar6)) &&

         (((fVar6 < (float)(param_2 + param_4) &&

           (fVar6 = *(float *)((longlong)plVar1 + 0x2c) * fVar2, (float)param_3 <= fVar6)) &&

          (fVar6 < (float)(param_3 + param_5))))) {

        (**(code **)(*plVar1 + 0x40))(plVar1,local_res8);

        FUN_140071000();

      }

      lVar5 = *(longlong *)(param_1 + 0xb8);

      iVar3 = iVar3 + 1;

      lVar4 = lVar4 + 8;

    } while ((ulonglong)(longlong)iVar3 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar5 >> 3));

  }

  FUN_140072860(1);

  return;

}




