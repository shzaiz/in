void update(int l, int r, int o, int pos)
{
    if (l == r)
        t[o]++;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(l, mid, ls(o), pos);
        else
            update(mid + 1, r, rs(o), pos);
        t[o] = t[ls(o)] + t[rs(o)];
    }
}
int query(int l, int r, int o, int pos)
{
    if (l == r)
        return t[o];
    else {
        if (pos <= mid)
            return query(l, mid, ls(o), pos);
        else
            return query(mid + 1, r, rs(o), pos);
    }
}

int query(int l, int r, int o, int x, int y)
{
    if (l == x && r == y)
        return t[o];
    else {
        int mid = (l + r) / 2;
        if (y <= mid)
            return (l, mid, ls(o), x, y);
        else if (x > mid)
            return query(mid + 1, r, rs(o), x, y);
        else
            return query(l, mid, ls(o), x, mid) + find(mid + 1, r, rs(o), mid + 1, y);
    }
}