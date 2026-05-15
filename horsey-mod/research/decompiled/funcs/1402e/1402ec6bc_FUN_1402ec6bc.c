// Address: 0x1402ec6bc
// Ghidra name: FUN_1402ec6bc
// ============ 0x1402ec6bc FUN_1402ec6bc (size=149) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



longlong FUN_1402ec6bc(void)



{

  code *pcVar1;

  longlong lVar2;

  

  if ((DAT_140424020 == (code *)0xffffffffffffffff) ||

     (((pcVar1 = DAT_140424020, DAT_140424020 == (code *)0x0 &&

       (pcVar1 = (code *)FUN_1402ec028(4,"GetActiveWindow",&DAT_14038ea28,"GetActiveWindow"),

       pcVar1 == (code *)0x0)) || (lVar2 = (*pcVar1)(), lVar2 == 0)))) {

    lVar2 = 0;

  }

  else if ((DAT_140424048 != (code *)0xffffffffffffffff) &&

          ((pcVar1 = DAT_140424048, DAT_140424048 != (code *)0x0 ||

           (pcVar1 = (code *)FUN_1402ec028(9,"GetLastActivePopup",&DAT_14038ea40,

                                           "GetLastActivePopup"), pcVar1 != (code *)0x0)))) {

    lVar2 = (*pcVar1)(lVar2);

    return lVar2;

  }

  return lVar2;

}




