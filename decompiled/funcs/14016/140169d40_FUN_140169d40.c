// Address: 0x140169d40
// Ghidra name: FUN_140169d40
// ============ 0x140169d40 FUN_140169d40 (size=300) ============


int FUN_140169d40(int param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  int local_28;

  int iStack_24;

  undefined8 local_20;

  undefined1 local_18 [16];

  

  iVar5 = 0;

  iVar7 = 0x7fffffff;

  local_28 = param_3 / 2 + param_1;

  iStack_24 = param_4 / 2 + param_2;

  if ((DAT_1403fc410 != 0) && (iVar4 = 0, 0 < *(int *)(DAT_1403fc410 + 0x328))) {

    lVar6 = 0;

    do {

      piVar1 = *(int **)(lVar6 + *(longlong *)(DAT_1403fc410 + 0x330));

      FUN_14016d280(*piVar1,local_18);

      cVar2 = FUN_1401854d0(&local_28,1,local_18,0);

      if (cVar2 != '\0') {

        return *piVar1;

      }

      local_20 = CONCAT44(iStack_24,local_28);

      FUN_14016d180(local_18,&local_20);

      iVar3 = (iStack_24 - local_20._4_4_) * (iStack_24 - local_20._4_4_) +

              (local_28 - (int)local_20) * (local_28 - (int)local_20);

      if (iVar3 < iVar7) {

        iVar5 = *piVar1;

        iVar7 = iVar3;

      }

      iVar4 = iVar4 + 1;

      lVar6 = lVar6 + 8;

    } while (iVar4 < *(int *)(DAT_1403fc410 + 0x328));

    if (iVar5 != 0) {

      return iVar5;

    }

  }

  FUN_14012e850("Couldn\'t find any displays");

  return 0;

}




