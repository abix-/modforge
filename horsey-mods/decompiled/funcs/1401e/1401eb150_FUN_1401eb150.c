// Address: 0x1401eb150
// Ghidra name: FUN_1401eb150
// ============ 0x1401eb150 FUN_1401eb150 (size=164) ============


void FUN_1401eb150(longlong param_1)



{

  longlong *plVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  

  plVar1 = *(longlong **)(param_1 + 0x40);

  if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0xd0) != 0)) &&

     (*(longlong *)(param_1 + 0xd8) != 0)) {

    (**(code **)(*plVar1 + 0x70))

              (plVar1,*(longlong *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xc0));

    uVar2 = *(ulonglong *)(param_1 + 0xc0);

    uVar3 = (**(code **)(**(longlong **)(param_1 + 0xd0) + 0x40))();

    if (uVar3 < uVar2) {

      (**(code **)(**(longlong **)(param_1 + 0xd0) + 0x48))

                (*(longlong **)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xc0),

                 *(undefined8 *)(param_1 + 0xd8));

      WaitForSingleObjectEx(*(HANDLE *)(param_1 + 0xd8),0xffffffff,0);

    }

    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 1;

  }

  return;

}




