void
gappedgrid(Monitor *m) {
    unsigned int i, n, cx, cy, cw, ch, cols, rows;
    Client *c;
    int oh, ov, ih, iv;

    /* Get gap values from vanity gaps */
    oh = m->gappoh;
    ov = m->gappov;
    ih = m->gappih;
    iv = m->gappiv;

    /* Count the number of tiled clients */
    for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);

    if (n == 0)
        return;

    /* Calculate rows and columns */
    for (cols = 0; cols <= n/2; cols++)
        if (cols * cols >= n)
            break;
    rows = (cols && (cols - 1) * cols >= n) ? cols - 1 : cols;

    /* Calculate cell dimensions, subtracting gaps */
    cw = cols ? (m->ww - 2 * ov - (cols - 1) * iv) / cols : m->ww - 2 * ov;
    ch = rows ? (m->wh - 2 * oh - (rows - 1) * ih) / rows : m->wh - 2 * oh;

    for (i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
        cx = m->wx + ov + (i % cols) * (cw + iv);
        cy = m->wy + oh + (i / cols) * (ch + ih);
        resize(c, cx, cy, cw - 2 * c->bw, ch - 2 * c->bw, 0);
    }
}

