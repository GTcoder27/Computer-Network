<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <table>
            <tr>
                <th>Title</th>
                <th>Author</th>
                <th>ISBN</th>
                <th>Publisher</th>
                <th>Edition</th>
                <th>Price</th>
            </tr>
            
            <xsl:for-each select="books/book">
                <tr>
                    <td><xsl:value-of select="title"/></td>
                    <td><xsl:value-of select="author"/></td>
                    <td><xsl:value-of select="isbn"/></td>
                    <td><xsl:value-of select="publisher"/></td>
                    <td><xsl:value-of select="edition"/></td>
                    <td><xsl:value-of select="price"/></td>
                </tr>
            </xsl:for-each>
        </table>
    </xsl:template>
</xsl:stylesheet>   