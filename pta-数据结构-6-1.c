List Reverse( List L )
{
    List new=NULL,old,head;//创建一个新链表，让旧链表中的每个结点使用头插法依次插入到新链表中
    old=L;
    while(old)
    {
        List temp=old->Next;
        old->Next=new;
        new=old;
        old=temp;
    }
    return new;
}
