// Address: 0x1401ac630
// Ghidra name: FUN_1401ac630
// ============ 0x1401ac630 FUN_1401ac630 (size=232) ============


void FUN_1401ac630(void)



{

  int iVar1;

  uint uVar2;

  ulonglong uVar3;

  uint local_res8 [2];

  longlong *local_res10;

  LPVOID local_res18;

  

  uVar3 = 0;

  local_res10 = (longlong *)0x0;

  iVar1 = (*DAT_1403fcde8)(&local_res10,1);

  if (-1 < iVar1) {

    iVar1 = (**(code **)(*local_res10 + 0xc0))(local_res10,&DAT_14033cbc0,&DAT_14033cbe0);

    if (iVar1 < 0) {

      (**(code **)(*local_res10 + 0x10))();

      return;

    }

    local_res18 = (LPVOID)0x0;

    local_res8[0] = 0;

    iVar1 = (*DAT_1403fcdc0)(local_res10,&local_res18,local_res8);

    (**(code **)(*local_res10 + 0x10))();

    if (-1 < iVar1) {

      if (local_res8[0] != 0) {

        do {

          FUN_1401acb50(*(undefined8 *)(uVar3 * 8 + (longlong)local_res18));

          (**(code **)(**(longlong **)(uVar3 * 8 + (longlong)local_res18) + 0x10))();

          uVar2 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar2;

        } while (uVar2 < local_res8[0]);

      }

      CoTaskMemFree(local_res18);

    }

  }

  return;

}




